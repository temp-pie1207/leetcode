// Last updated: 17/07/2026, 21:50:05
1#include <stdlib.h>
2
3int cmp(const void *a, const void *b) {
4    return (*(int *)a - *(int *)b);
5}
6
7int* gcdValues(int* nums, int numsSize, long long* queries, int queriesSize, int* returnSize) {
8    *returnSize = queriesSize;
9
10    int mx = 0;
11    for (int i = 0; i < numsSize; i++)
12        if (nums[i] > mx) mx = nums[i];
13
14    int *freq = calloc(mx + 1, sizeof(int));
15    for (int i = 0; i < numsSize; i++)
16        freq[nums[i]]++;
17
18    long long *cnt = calloc(mx + 1, sizeof(long long));
19
20    // Count pairs with gcd divisible by i
21    for (int i = mx; i >= 1; i--) {
22        long long c = 0;
23        for (int j = i; j <= mx; j += i)
24            c += freq[j];
25
26        cnt[i] = c * (c - 1) / 2;
27
28        for (int j = i * 2; j <= mx; j += i)
29            cnt[i] -= cnt[j];
30    }
31
32    long long *prefix = calloc(mx + 1, sizeof(long long));
33    for (int i = 1; i <= mx; i++)
34        prefix[i] = prefix[i - 1] + cnt[i];
35
36    int *ans = malloc(sizeof(int) * queriesSize);
37
38    for (int i = 0; i < queriesSize; i++) {
39        long long k = queries[i] + 1;
40
41        int l = 1, r = mx;
42        while (l < r) {
43            int mid = l + (r - l) / 2;
44            if (prefix[mid] >= k)
45                r = mid;
46            else
47                l = mid + 1;
48        }
49
50        ans[i] = l;
51    }
52
53    free(freq);
54    free(cnt);
55    free(prefix);
56
57    return ans;
58}