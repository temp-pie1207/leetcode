// Last updated: 11/07/2026, 16:34:23
1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4int* getConcatenation(int* nums, int numsSize, int* returnSize) {
5    *returnSize=2*numsSize;
6    int *ans=(int*)malloc((*returnSize)*sizeof(int));
7    for(int i=0;i<numsSize;i++){
8        ans[i] = nums[i];
9        ans[i + numsSize] = nums[i];
10    }
11return ans;
12}