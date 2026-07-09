// Last updated: 09/07/2026, 16:26:59
1bool isPowerOfTwo(int n) {
2    if (n <= 0)
3        return false;
4
5    while (n % 2 == 0)
6        n = n / 2;
7
8    return n == 1;
9}