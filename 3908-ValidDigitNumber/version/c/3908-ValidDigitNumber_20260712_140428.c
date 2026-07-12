// Last updated: 12/07/2026, 14:04:28
1bool validDigit(int n, int x) {
2    int temp = n;
3
4
5    while (temp >= 10)
6        temp /= 10;
7
8    if (temp == x)
9        return false;
10
11
12    while (n > 0) {
13        if (n % 10 == x)
14            return true;
15        n /= 10;
16    }
17
18    return false;
19}