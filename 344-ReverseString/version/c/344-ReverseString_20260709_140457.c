// Last updated: 09/07/2026, 14:04:57
1bool isPerfectSquare(int num) {
2    long i;
3
4    for (i = 1; i * i <= num; i++) {
5        if (i * i == num)
6            return true;
7    }
8
9    return false;
10}