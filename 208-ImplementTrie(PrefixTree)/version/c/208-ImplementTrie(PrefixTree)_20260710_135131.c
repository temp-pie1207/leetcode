// Last updated: 10/07/2026, 13:51:31
1#include <limits.h>
2#include <stdlib.h>
3
4int numSquares(int n) {
5    int *dp = (int *)malloc((n + 1) * sizeof(int));
6
7    dp[0] = 0;
8
9    for (int i = 1; i <= n; i++) {
10        dp[i] = INT_MAX;
11
12        for (int j = 1; j * j <= i; j++) {
13            if (dp[i - j * j] + 1 < dp[i])
14                dp[i] = dp[i - j * j] + 1;
15        }
16    }
17
18    int ans = dp[n];
19    free(dp);
20    return ans;
21}