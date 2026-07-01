// Last updated: 01/07/2026, 11:19:54
1#include <ctype.h>
2
3bool detectCapitalUse(char* word) {
4    int upper = 0;
5    int len = 0;
6
7    for (int i = 0; word[i] != '\0'; i++) {
8        len++;
9        if (isupper(word[i]))
10            upper++;
11    }
12
13    if (upper == len)          
14        return true;
15    if (upper == 0)           
16        return true;
17    if (upper == 1 && isupper(word[0])) 
18        return true;
19
20    return false;
21}