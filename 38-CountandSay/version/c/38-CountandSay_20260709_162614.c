// Last updated: 09/07/2026, 16:26:14
1bool isPowerOfTwo(int n) {
2    if (n <= 0)
3        return false;
4
5    return (n & (n - 1)) == 0;
6}