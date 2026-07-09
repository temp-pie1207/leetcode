// Last updated: 09/07/2026, 13:32:09
1#include <stdio.h>
2#include <stdlib.h>
3#include <string.h>
4
5int cmp(const void *a, const void *b)
6{
7    char ab[25], ba[25];
8    sprintf(ab, "%d%d", *(int *)a, *(int *)b);
9    sprintf(ba, "%d%d", *(int *)b, *(int *)a);
10
11    return strcmp(ba, ab);
12}
13
14char* largestNumber(int* nums, int numsSize)
15{
16    qsort(nums, numsSize, sizeof(int), cmp);
17
18    if (nums[0] == 0)
19    {
20        char *ans = (char *)malloc(2);
21        strcpy(ans, "0");
22        return ans;
23    }
24
25    char *ans = (char *)malloc(numsSize * 11 + 1);
26    ans[0] = '\0';
27
28    char temp[12];
29
30    for (int i = 0; i < numsSize; i++)
31    {
32        sprintf(temp, "%d", nums[i]);
33        strcat(ans, temp);
34    }
35
36    return ans;
37}