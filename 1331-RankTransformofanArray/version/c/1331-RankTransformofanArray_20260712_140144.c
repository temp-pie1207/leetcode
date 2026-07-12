// Last updated: 12/07/2026, 14:01:44
1#include <stdlib.h>
2
3typedef struct {
4    int val;
5    int index;
6} Pair;
7
8int compare(const void *a, const void *b) {
9    return ((Pair *)a)->val - ((Pair *)b)->val;
10}
11
12int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
13    *returnSize = arrSize;
14
15    if (arrSize == 0)
16        return NULL;
17
18    Pair p[arrSize];
19    int *ans = (int *)malloc(arrSize * sizeof(int));
20
21    for (int i = 0; i < arrSize; i++) {
22        p[i].val = arr[i];
23        p[i].index = i;
24    }
25
26    qsort(p, arrSize, sizeof(Pair), compare);
27
28    int rank = 1;
29    ans[p[0].index] = rank;
30
31    for (int i = 1; i < arrSize; i++) {
32        if (p[i].val != p[i - 1].val)
33            rank++;
34
35        ans[p[i].index] = rank;
36    }
37
38    return ans;
39}