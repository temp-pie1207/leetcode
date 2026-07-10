// Last updated: 10/07/2026, 14:01:39
1#include <stdlib.h>
2
3char* toHex(int num) {
4    if (num == 0) {
5        char *res = (char *)malloc(2);
6        res[0] = '0';
7        res[1] = '\0';
8        return res;
9    }
10
11    char hex[] = "0123456789abcdef";
12    char *res = (char *)malloc(9);
13    res[8] = '\0';
14
15    unsigned int n = (unsigned int)num;
16    int i = 7;
17
18    while (n != 0) {
19        res[i--] = hex[n % 16];
20        n /= 16;
21    }
22
23    return res + i + 1;
24}