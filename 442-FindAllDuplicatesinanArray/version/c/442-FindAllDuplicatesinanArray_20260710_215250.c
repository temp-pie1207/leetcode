// Last updated: 10/07/2026, 21:52:50
1#include <stdlib.h>
2
3int* findDuplicates(int* nums, int numsSize, int* returnSize) {
4    int *ans = (int *)malloc(numsSize * sizeof(int));
5    *returnSize = 0;
6
7    for (int i = 0; i < numsSize; i++) {
8        int index = abs(nums[i]) - 1;
9
10        if (nums[index] < 0)
11            ans[(*returnSize)++] = index + 1;
12        else
13            nums[index] = -nums[index];
14    }
15
16    return ans;
17}