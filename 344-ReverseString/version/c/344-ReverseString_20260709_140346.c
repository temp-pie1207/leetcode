// Last updated: 09/07/2026, 14:03:46
1#include <stdlib.h>
2
3int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
4    int seen[1001] = {0};
5    int added[1001] = {0};
6
7    for (int i = 0; i < nums1Size; i++) {
8        seen[nums1[i]] = 1;
9    }
10
11    int *result = (int *)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
12    *returnSize = 0;
13
14    for (int i = 0; i < nums2Size; i++) {
15        if (seen[nums2[i]] && !added[nums2[i]]) {
16            result[(*returnSize)++] = nums2[i];
17            added[nums2[i]] = 1;
18        }
19    }
20
21    return result;
22}