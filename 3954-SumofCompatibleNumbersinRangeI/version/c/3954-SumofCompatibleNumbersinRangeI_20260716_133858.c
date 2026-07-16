// Last updated: 16/07/2026, 13:38:58
1
2    
3int sumOfGoodIntegers(int n, int k) {
4    int sum = 0;
5
6    int start = n - k;
7    if (start < 1)
8        start = 1;
9
10    int end = n + k;
11
12    for (int x = start; x <= end; x++) {
13        if ((n & x) == 0) {
14            sum += x;
15        }
16    }
17
18    return sum;
19}