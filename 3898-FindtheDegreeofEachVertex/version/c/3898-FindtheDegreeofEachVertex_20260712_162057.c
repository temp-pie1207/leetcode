// Last updated: 12/07/2026, 16:20:57
1#include <string.h>
2
3int firstMatchingIndex(char* s) {
4    int n = strlen(s);
5
6    for (int i = 0; i < n; i++) {
7        if (s[i] == s[n - i - 1])
8            return i;
9    }
10
11    return -1;
12}