// Last updated: 11/07/2026, 15:36:40
1int range(int n) {
2    int mn = 9, mx = 0;
3
4    while (n > 0) {
5        int d = n % 10;
6        if (d < mn) mn = d;
7        if (d > mx) mx = d;
8        n /= 10;
9    }
10
11    return mx - mn;
12}
13
14int maxDigitRange(int* nums, int numsSize) {
15    int maxRange = -1, sum = 0;
16
17
18    for (int i = 0; i < numsSize; i++) {
19        int r = range(nums[i]);
20        if (r > maxRange)
21            maxRange = r;
22    }
23
24
25    for (int i = 0; i < numsSize; i++) {
26        if (range(nums[i]) == maxRange)
27            sum += nums[i];
28    }
29
30    return sum;
31}