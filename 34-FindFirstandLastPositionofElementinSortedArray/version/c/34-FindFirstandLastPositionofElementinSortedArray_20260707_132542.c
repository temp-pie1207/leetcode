// Last updated: 07/07/2026, 13:25:42
1#include <stdio.h>
2#include <stdlib.h>
3#include <string.h>
4
5char* countAndSay(int n) {
6    char *s = (char *)malloc(5000);
7    strcpy(s, "1");
8
9    for (int i = 2; i <= n; i++) {
10        char *temp = (char *)malloc(5000);
11        int k = 0;
12
13        for (int j = 0; s[j] != '\0'; ) {
14            int count = 1;
15
16            while (s[j] == s[j + 1]) {
17                count++;
18                j++;
19            }
20
21            temp[k++] = count + '0';
22            temp[k++] = s[j];
23            j++;
24        }
25
26        temp[k] = '\0';
27        strcpy(s, temp);
28        free(temp);
29    }
30
31    return s;
32}