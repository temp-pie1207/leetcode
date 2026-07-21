// Last updated: 21/07/2026, 16:01:22
1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
5
6    int *ans = (int *)malloc(sizeof(int) * numsSize);
7
8    int j = 0;
9
10    for (int i = 0; i < n; i++) {
11        ans[j++] = nums[i];
12        ans[j++] = nums[i + n];
13    }
14
15    *returnSize = numsSize;
16    return ans;
17}