// Last updated: 01/07/2026, 11:19:14
1bool detectCapitalUse(char* word) {
2    int upper = 0, len = 0;
3
4    for (int i = 0; word[i]; i++) {
5        len++;
6        if (word[i] >= 'A' && word[i] <= 'Z')
7            upper++;
8    }
9
10    return (upper == len || upper == 0 || (upper == 1 && word[0] >= 'A' && word[0] <= 'Z'));
11}