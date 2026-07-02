// Last updated: 02/07/2026, 21:23:14
1#include <stdbool.h>
2#include <stdlib.h>
3
4bool findSafeWalk(int** grid, int gridSize, int* gridColSize, int health) {
5    int m = gridSize;
6    int n = gridColSize[0];
7
8    int best[m][n];
9    for (int i = 0; i < m; i++)
10        for (int j = 0; j < n; j++)
11            best[i][j] = -1;
12
13    int startHealth = health - grid[0][0];
14    if (startHealth < 1) return false;
15
16    // Maximum possible states: each cell with multiple health values
17    int maxStates = m * n * health;
18
19    int *qx = malloc(sizeof(int) * maxStates);
20    int *qy = malloc(sizeof(int) * maxStates);
21    int *qh = malloc(sizeof(int) * maxStates);
22
23    int front = 0, back = 0;
24
25    qx[back] = 0;
26    qy[back] = 0;
27    qh[back] = startHealth;
28    back++;
29
30    best[0][0] = startHealth;
31
32    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
33
34    while (front < back) {
35        int x = qx[front];
36        int y = qy[front];
37        int h = qh[front];
38        front++;
39
40        if (x == m - 1 && y == n - 1) {
41            free(qx); free(qy); free(qh);
42            return true;
43        }
44
45        for (int d = 0; d < 4; d++) {
46            int nx = x + dirs[d][0];
47            int ny = y + dirs[d][1];
48
49            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
50                continue;
51
52            int nh = h - grid[nx][ny];
53            if (nh >= 1 && nh > best[nx][ny]) {
54                best[nx][ny] = nh;
55                qx[back] = nx;
56                qy[back] = ny;
57                qh[back] = nh;
58                back++;
59            }
60        }
61    }
62
63    free(qx); free(qy); free(qh);
64    return false;
65}