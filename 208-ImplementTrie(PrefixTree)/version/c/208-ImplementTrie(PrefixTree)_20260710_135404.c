// Last updated: 10/07/2026, 13:54:04
1#include <string.h>
2#include <stdbool.h>
3
4bool wordPattern(char* pattern, char* s) {
5    char *map[26] = {0};
6    char *used[300] = {0};
7    int count = 0;
8
9    char *word = strtok(s, " ");
10    int i = 0;
11
12    while (word != NULL && pattern[i] != '\0') {
13        int idx = pattern[i] - 'a';
14
15        if (map[idx] == NULL) {
16            for (int j = 0; j < count; j++) {
17                if (strcmp(used[j], word) == 0)
18                    return false;
19            }
20            map[idx] = word;
21            used[count++] = word;
22        } else {
23            if (strcmp(map[idx], word) != 0)
24                return false;
25        }
26
27        word = strtok(NULL, " ");
28        i++;
29    }
30
31    return (word == NULL && pattern[i] == '\0');
32}