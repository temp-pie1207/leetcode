// Last updated: 10/07/2026, 14:02:50
1#include <limits.h>
2
3int thirdMax(int* nums, int numsSize) {
4    long long first = LLONG_MIN;
5    long long second = LLONG_MIN;
6    long long third = LLONG_MIN;
7
8    for (int i = 0; i < numsSize; i++) {
9        if (nums[i] == first || nums[i] == second || nums[i] == third)
10            continue;
11
12        if (nums[i] > first) {
13            third = second;
14            second = first;
15            first = nums[i];
16        }
17        else if (nums[i] > second) {
18            third = second;
19            second = nums[i];
20        }
21        else if (nums[i] > third) {
22            third = nums[i];
23        }
24    }
25
26    return (third == LLONG_MIN) ? first : third;
27}