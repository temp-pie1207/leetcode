// Last updated: 12/07/2026, 16:25:57
1int countCommas(int n) {
2    if (n < 1000)
3        return 0;
4
5    return n - 999;
6}