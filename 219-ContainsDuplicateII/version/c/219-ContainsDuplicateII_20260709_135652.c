// Last updated: 09/07/2026, 13:56:52
1void reverseString(char* s, int sSize) {
2    int left = 0;
3    int right = sSize - 1;
4
5    while (left < right) {
6        char temp = s[left];
7        s[left] = s[right];
8        s[right] = temp;
9
10        left++;
11        right--;
12    }
13}