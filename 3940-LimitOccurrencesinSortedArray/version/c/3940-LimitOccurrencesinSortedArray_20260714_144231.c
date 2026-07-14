// Last updated: 14/07/2026, 14:42:31
1#include <stdlib.h>
2
3int* limitOccurrences(int* nums, int numsSize, int k, int* returnSize) {
4    int *ans = (int *)malloc(numsSize * sizeof(int));
5    int i1 = 0;
6
7    for (int i = 0; i < numsSize; ) {
8        int val = nums[i];
9        int cnt = 0;
10
11        while (i < numsSize && nums[i] == val) {
12            if (cnt < k) {
13                ans[i1++] = nums[i];
14            }
15            cnt++;
16            i++;
17        }
18    }
19
20    *returnSize = i1;
21    return ans;
22}