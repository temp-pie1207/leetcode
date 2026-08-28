// Last updated: 28/08/2026, 14:51:18
1struct ListNode* rotateRight(struct ListNode* head, int k) {
2    if (head == NULL || head->next == NULL || k == 0)
3        return head;
4
5    int len = 1;
6    struct ListNode* tail = head;
7
8    while (tail->next != NULL) {
9        tail = tail->next;
10        len++;
11    }
12
13    k = k % len;
14
15    if (k == 0)
16        return head;
17
18    tail->next = head;
19
20    int steps = len - k;
21    struct ListNode* newTail = head;
22
23    for (int i = 1; i < steps; i++)
24        newTail = newTail->next;
25
26    struct ListNode* newHead = newTail->next;
27
28    newTail->next = NULL;
29
30    return newHead;
31}