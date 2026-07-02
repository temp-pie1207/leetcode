// Last updated: 02/07/2026, 21:13:36
1#include <stdlib.h>
2#include <stdbool.h>
3
4int dr[4] = {-1, 1, 0, 0};
5int dc[4] = {0, 0, -1, 1};
6
7int maximumSafenessFactor(int** grid, int n, int* gridColSize) {
8    int **dist = (int**)malloc(n * sizeof(int*));
9    for (int i = 0; i < n; i++) {
10        dist[i] = (int*)malloc(n * sizeof(int));
11    }
12
13  
14    int *qr = (int*)malloc(n * n * sizeof(int));
15    int *qc = (int*)malloc(n * n * sizeof(int));
16    int front = 0, rear = 0;
17
18
19    for (int i = 0; i < n; i++) {
20        for (int j = 0; j < n; j++) {
21            if (grid[i][j] == 1) {
22                dist[i][j] = 0;
23                qr[rear] = i;
24                qc[rear] = j;
25                rear++;
26            } else {
27                dist[i][j] = 1000000;
28            }
29        }
30    }
31
32    while (front < rear) {
33        int r = qr[front];
34        int c = qc[front];
35        front++;
36
37        for (int k = 0; k < 4; k++) {
38            int nr = r + dr[k];
39            int nc = c + dc[k];
40
41            if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
42                dist[nr][nc] > dist[r][c] + 1) {
43
44                dist[nr][nc] = dist[r][c] + 1;
45                qr[rear] = nr;
46                qc[rear] = nc;
47                rear++;
48            }
49        }
50    }
51
52    int low = 0, high = 2 * n, ans = 0;
53
54    while (low <= high) {
55        int mid = (low + high) / 2;
56
57        if (dist[0][0] < mid || dist[n-1][n-1] < mid) {
58            high = mid - 1;
59            continue;
60        }
61
62        bool **vis = (bool**)malloc(n * sizeof(bool*));
63        for (int i = 0; i < n; i++) {
64            vis[i] = (bool*)calloc(n, sizeof(bool));
65        }
66
67        front = rear = 0;
68        qr[rear] = 0;
69        qc[rear] = 0;
70        rear++;
71        vis[0][0] = true;
72
73        bool ok = false;
74
75        while (front < rear) {
76            int r = qr[front];
77            int c = qc[front];
78            front++;
79
80            if (r == n - 1 && c == n - 1) {
81                ok = true;
82                break;
83            }
84
85            for (int k = 0; k < 4; k++) {
86                int nr = r + dr[k];
87                int nc = c + dc[k];
88
89                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
90                    !vis[nr][nc] && dist[nr][nc] >= mid) {
91
92                    vis[nr][nc] = true;
93                    qr[rear] = nr;
94                    qc[rear] = nc;
95                    rear++;
96                }
97            }
98        }
99
100        for (int i = 0; i < n; i++) free(vis[i]);
101        free(vis);
102
103        if (ok) {
104            ans = mid;
105            low = mid + 1;
106        } else {
107            high = mid - 1;
108        }
109    }
110
111    for (int i = 0; i < n; i++) free(dist[i]);
112    free(dist);
113    free(qr);
114    free(qc);
115
116    return ans;
117}