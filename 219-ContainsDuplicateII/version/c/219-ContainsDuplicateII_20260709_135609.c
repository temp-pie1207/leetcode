// Last updated: 09/07/2026, 13:56:09
1bool isPowerOfFour(int n) {
2    return n > 0 &&
3           (n & (n - 1)) == 0 &&
4           (n & 0x55555555) != 0;
5}