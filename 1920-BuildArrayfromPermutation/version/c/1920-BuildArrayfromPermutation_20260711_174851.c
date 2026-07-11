// Last updated: 11/07/2026, 17:48:51
1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4int* buildArray(int* nums, int numsSize, int* returnSize) {
5    int *ans= (int*)malloc(numsSize*sizeof(int));
6    for(int i=0;i<numsSize;i++){
7        ans[i] = nums[nums[i]];
8    }
9    *returnSize=numsSize;
10    return ans;
11    
12}