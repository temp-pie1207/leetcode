// Last updated: 14/07/2026, 14:35:54
1#define MAXG 200
2#define MOD 1000000007LL
3
4int gcd(int a, int b) {
5    while (b) {
6        int t = a % b;
7        a = b;
8        b = t;
9    }
10    return a;
11}
12
13int subsequencePairCount(int* nums, int numsSize) {
14    static long long dp[MAXG + 1][MAXG + 1];
15    static long long ndp[MAXG + 1][MAXG + 1];
16
17    memset(dp, 0, sizeof(dp));
18    dp[0][0] = 1;
19
20    for (int idx = 0; idx < numsSize; idx++) {
21        int x = nums[idx];
22
23        memcpy(ndp, dp, sizeof(dp));
24
25        for (int g1 = 0; g1 <= MAXG; g1++) {
26            for (int g2 = 0; g2 <= MAXG; g2++) {
27                long long cur = dp[g1][g2];
28                if (!cur) continue;
29
30                int ng1 = (g1 == 0) ? x : gcd(g1, x);
31                int ng2 = (g2 == 0) ? x : gcd(g2, x);
32
33                ndp[ng1][g2] = (ndp[ng1][g2] + cur) % MOD;
34                ndp[g1][ng2] = (ndp[g1][ng2] + cur) % MOD;
35            }
36        }
37
38        memcpy(dp, ndp, sizeof(dp));
39    }
40
41    long long ans = 0;
42    for (int g = 1; g <= MAXG; g++) {
43        ans = (ans + dp[g][g]) % MOD;
44    }
45
46    return (int)ans;
47}