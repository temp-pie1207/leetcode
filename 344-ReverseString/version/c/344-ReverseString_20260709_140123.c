// Last updated: 09/07/2026, 14:01:23
1bool isVowel(char c) {
2    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
3           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
4}
5
6char* reverseVowels(char* s) {
7    int left = 0;
8    int right = strlen(s) - 1;
9
10    while (left < right) {
11        while (left < right && !isVowel(s[left]))
12            left++;
13
14        while (left < right && !isVowel(s[right]))
15            right--;
16
17        char temp = s[left];
18        s[left] = s[right];
19        s[right] = temp;
20
21        left++;
22        right--;
23    }
24
25    return s;
26}