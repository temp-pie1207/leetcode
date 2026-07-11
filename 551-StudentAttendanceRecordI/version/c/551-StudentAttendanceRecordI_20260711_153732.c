// Last updated: 11/07/2026, 15:37:32
1int* concatWithReverse(int* nums, int numsSize, int* returnSize) {
2    *returnSize = 2 * numsSize;
3
4    int *ans = (int *)malloc((*returnSize) * sizeof(int));
5
6    for (int i = 0; i < numsSize; i++) {
7        ans[i] = nums[i];
8        ans[numsSize + i] = nums[numsSize - 1 - i];
9    }
10
11    return ans;
12}