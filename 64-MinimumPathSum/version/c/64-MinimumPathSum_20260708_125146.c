// Last updated: 08/07/2026, 12:51:46
1int minPathSum(int** grid, int gridSize, int* gridColSize) {
2    int m = gridSize;
3    int n = gridColSize[0];
4
5  
6    for (int j = 1; j < n; j++)
7        grid[0][j] += grid[0][j - 1];
8
9   
10    for (int i = 1; i < m; i++)
11        grid[i][0] += grid[i - 1][0];
12
13    
14    for (int i = 1; i < m; i++) {
15        for (int j = 1; j < n; j++) {
16            if (grid[i - 1][j] < grid[i][j - 1])
17                grid[i][j] += grid[i - 1][j];
18            else
19                grid[i][j] += grid[i][j - 1];
20        }
21    }
22
23    return grid[m - 1][n - 1];
24}