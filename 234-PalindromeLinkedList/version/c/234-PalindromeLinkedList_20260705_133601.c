// Last updated: 05/07/2026, 13:36:01
1bool isPalindrome(struct ListNode* head) {
2    int arr[100000];
3    int n = 0;
4    while (head != NULL) {
5        arr[n++] = head->val;
6        head = head->next;
7    }
8    int i = 0, j = n - 1;
9    while (i < j) {
10        if (arr[i] != arr[j])
11            return false;
12        i++;
13        j--;
14    }
15
16    return true;
17}