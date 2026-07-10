// Last updated: 10/07/2026, 14:00:11
1int findNthDigit(int n) {
2    long long digits = 1;
3    long long count = 9;
4    long long start = 1;
5
6    while (n > digits * count) {
7        n -= digits * count;
8        digits++;
9        count *= 10;
10        start *= 10;
11    }
12
13    start += (n - 1) / digits;
14
15    int index = (n - 1) % digits;
16
17    while (index < digits - 1) {
18        start /= 10;
19        digits--;
20    }
21
22    return start % 10;
23}