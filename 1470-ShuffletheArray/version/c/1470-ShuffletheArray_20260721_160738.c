// Last updated: 21/07/2026, 16:07:38
1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4int* plusOne(int* digits, int digitsSize, int* returnSize) {
5
6    // Traverse from the last digit
7    for (int i = digitsSize - 1; i >= 0; i--) {
8
9        if (digits[i] < 9) {
10            digits[i]++;
11            *returnSize = digitsSize;
12            return digits;
13        }
14
15        digits[i] = 0;
16    }
17
18    // All digits were 9
19    int *ans = (int *)malloc((digitsSize + 1) * sizeof(int));
20
21    ans[0] = 1;
22
23    for (int i = 1; i <= digitsSize; i++)
24        ans[i] = 0;
25
26    *returnSize = digitsSize + 1;
27
28    return ans;
29}