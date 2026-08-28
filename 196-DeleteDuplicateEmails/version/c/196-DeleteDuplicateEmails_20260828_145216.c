// Last updated: 28/08/2026, 14:52:16
1int uniquePaths(int m, int n) {
2    int dp[101][101] = {0};
3
4    for (int i = 0; i < m; i++)
5        dp[i][0] = 1;
6
7    for (int j = 0; j < n; j++)
8        dp[0][j] = 1;
9
10    for (int i = 1; i < m; i++) {
11        for (int j = 1; j < n; j++) {
12            dp[i][j] = dp[i-1][j] + dp[i][j-1];
13        }
14    }
15
16    return dp[m-1][n-1];
17}