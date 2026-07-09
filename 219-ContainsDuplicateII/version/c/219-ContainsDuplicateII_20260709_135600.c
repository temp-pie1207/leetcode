// Last updated: 09/07/2026, 13:56:00
1bool isPowerOfFour(int n) {
2    if (n <= 0) return false;
3
4    while (n % 4 == 0) {
5        n /= 4;
6    }
7
8    return n == 1;
9}