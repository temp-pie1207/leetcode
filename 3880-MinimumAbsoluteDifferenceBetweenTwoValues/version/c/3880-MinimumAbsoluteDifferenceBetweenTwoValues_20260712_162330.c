// Last updated: 12/07/2026, 16:23:30
1#include <stdlib.h>
2
3int minAbsoluteDifference(int* nums, int numsSize) {
4    int min = 101;   
5    for (int i = 0; i < numsSize; i++) {
6        if (nums[i] == 1) {
7            for (int j = 0; j < numsSize; j++) {
8                if (nums[j] == 2) {
9                    if (abs(i - j) < min)
10                        min = abs(i - j);
11                }
12            }
13        }
14    }
15
16    if (min == 101)
17        return -1;
18
19    return min;
20}