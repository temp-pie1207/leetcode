// Last updated: 13/07/2026, 13:24:24
1long long countCommas(long long n) {
2    long long ans = 0;
3    long long start = 1000;
4    int commas = 1;
5
6    while (start <= n) {
7        long long end = start * 1000 - 1;
8        if (end > n)
9            end = n;
10
11        ans += (end - start + 1) * commas;
12
13        start *= 1000;
14        commas++;
15    }
16
17    return ans;
18}