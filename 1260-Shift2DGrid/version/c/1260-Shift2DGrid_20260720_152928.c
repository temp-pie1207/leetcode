// Last updated: 20/07/2026, 15:29:28
1int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k,
2                int* returnSize, int** returnColumnSizes) {
3
4    int m = gridSize;
5    int n = gridColSize[0];
6    int total = m * n;
7
8    k %= total;
9
10    int **ans = (int **)malloc(sizeof(int *) * m);
11    *returnColumnSizes = (int *)malloc(sizeof(int) * m);
12
13    for (int i = 0; i < m; i++) {
14        ans[i] = (int *)malloc(sizeof(int) * n);
15        (*returnColumnSizes)[i] = n;
16    }
17
18    for (int i = 0; i < m; i++) {
19        for (int j = 0; j < n; j++) {
20
21            int index = i * n + j;
22            int newIndex = (index + k) % total;
23
24            int newRow = newIndex / n;
25            int newCol = newIndex % n;
26
27            ans[newRow][newCol] = grid[i][j];
28        }
29    }
30
31    *returnSize = m;
32    return ans;
33}