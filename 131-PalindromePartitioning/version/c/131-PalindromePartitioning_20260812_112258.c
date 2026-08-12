// Last updated: 12/08/2026, 11:22:58
1#include <stdlib.h>
2#include <string.h>
3
4int isPalindrome(char *s, int l, int r) {
5    while (l < r) {
6        if (s[l] != s[r])
7            return 0;
8        l++;
9        r--;
10    }
11    return 1;
12}
13
14void backtrack(char *s, int start, int n, char **path, int pathSize,
15               char ***ans, int *returnSize, int *returnColumnSizes) {
16    if (start == n) {
17        ans[*returnSize] = malloc(sizeof(char *) * pathSize);
18
19        for (int i = 0; i < pathSize; i++) {
20            ans[*returnSize][i] = malloc(strlen(path[i]) + 1);
21            strcpy(ans[*returnSize][i], path[i]);
22        }
23
24        returnColumnSizes[*returnSize] = pathSize;
25        (*returnSize)++;
26        return;
27    }
28
29    for (int end = start; end < n; end++) {
30        if (isPalindrome(s, start, end)) {
31            int len = end - start + 1;
32
33            path[pathSize] = malloc(len + 1);
34            strncpy(path[pathSize], s + start, len);
35            path[pathSize][len] = '\0';
36
37            backtrack(s, end + 1, n, path, pathSize + 1,
38                      ans, returnSize, returnColumnSizes);
39
40            free(path[pathSize]);
41        }
42    }
43}
44
45char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
46    int n = strlen(s);
47
48    char ***ans = malloc(sizeof(char **) * (1 << n));
49    *returnColumnSizes = malloc(sizeof(int) * (1 << n));
50
51    char **path = malloc(sizeof(char *) * n);
52
53    *returnSize = 0;
54
55    backtrack(s, 0, n, path, 0,
56              ans, returnSize, *returnColumnSizes);
57
58    free(path);
59
60    return ans;
61}