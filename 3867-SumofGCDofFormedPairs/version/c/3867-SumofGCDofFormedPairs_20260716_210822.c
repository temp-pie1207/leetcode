// Last updated: 16/07/2026, 21:08:22
1int gcd(int a, int b) {
2    while (b) {
3        int t = a % b;
4        a = b;
5        b = t;
6    }
7    return a;
8}
9
10int cmp(const void *a, const void *b) {
11    return (*(int *)a - *(int *)b);
12}
13
14long long gcdSum(int* nums, int numsSize) {
15    int *prefixGcd = (int *)malloc(numsSize * sizeof(int));
16
17    int mx = nums[0];
18    for (int i = 0; i < numsSize; i++) {
19        if (nums[i] > mx)
20            mx = nums[i];
21        prefixGcd[i] = gcd(nums[i], mx);
22    }
23
24    qsort(prefixGcd, numsSize, sizeof(int), cmp);
25
26    long long ans = 0;
27    int l = 0, r = numsSize - 1;
28
29    while (l < r) {
30        ans += gcd(prefixGcd[l], prefixGcd[r]);
31        l++;
32        r--;
33    }
34
35    free(prefixGcd);
36    return ans;
37}