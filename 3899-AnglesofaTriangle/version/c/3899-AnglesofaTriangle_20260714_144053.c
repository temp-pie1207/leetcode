// Last updated: 14/07/2026, 14:40:53
1#include <stdlib.h>
2#include <math.h>
3
4#define PI acos(-1.0)
5
6int cmp(const void *a, const void *b) {
7    double x = *(double *)a;
8    double y = *(double *)b;
9    if (x < y) return -1;
10    if (x > y) return 1;
11    return 0;
12}
13
14double* internalAngles(int* sides, int sidesSize, int* returnSize) {
15    int a = sides[0], b = sides[1], c = sides[2];
16
17  
18    if (a + b <= c || a + c <= b || b + c <= a) {
19        *returnSize = 0;
20        return NULL;
21    }
22
23    *returnSize = 3;
24    double *ans = (double *)malloc(3 * sizeof(double));
25
26    ans[0] = acos((b * b + c * c - a * a) / (2.0 * b * c)) * 180.0 / PI;
27    ans[1] = acos((a * a + c * c - b * b) / (2.0 * a * c)) * 180.0 / PI;
28    ans[2] = acos((a * a + b * b - c * c) / (2.0 * a * b)) * 180.0 / PI;
29
30    qsort(ans, 3, sizeof(double), cmp);
31
32    return ans;
33}