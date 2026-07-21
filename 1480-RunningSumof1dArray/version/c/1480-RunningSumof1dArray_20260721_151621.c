// Last updated: 21/07/2026, 15:16:21
1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4int* runningSum(int* nums, int numsSize, int* returnSize) {
5    int n = numsSize;
6    int j=0;
7    int *a = (int*)malloc(n * sizeof(int));
8    int sum = 0;
9    for(int i=0;i<n;i++){
10        sum = sum+ nums[i];
11        a[j] = sum;
12        j++;
13    }
14    *returnSize = n;
15    return a;
16    
17}