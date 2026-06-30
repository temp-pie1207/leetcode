// Last updated: 30/06/2026, 16:05:10
1#include <stdlib.h>
2
3int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
4    *returnSize = 2;
5    int* result = (int*)malloc(2 * sizeof(int));
6
7    for (int i = 0; i < numsSize; i++) {
8        for (int j = i + 1; j < numsSize; j++) {
9            if (nums[i] + nums[j] == target) {
10                result[0] = i;
11                result[1] = j;
12                return result;
13            }
14        }
15    }
16
17    return NULL; // should never happen
18}