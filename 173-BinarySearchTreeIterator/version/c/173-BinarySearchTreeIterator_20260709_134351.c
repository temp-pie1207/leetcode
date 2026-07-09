// Last updated: 09/07/2026, 13:43:51
1#include <stdlib.h>
2
3int compare(const void *a, const void *b)
4{
5    return (*(int *)a - *(int *)b);
6}
7
8bool containsDuplicate(int* nums, int numsSize)
9{
10    if(numsSize <= 1)
11        return false;
12
13    qsort(nums, numsSize, sizeof(int), compare);
14
15    for(int i = 1; i < numsSize; i++)
16    {
17        if(nums[i] == nums[i - 1])
18            return true;
19    }
20
21    return false;
22}