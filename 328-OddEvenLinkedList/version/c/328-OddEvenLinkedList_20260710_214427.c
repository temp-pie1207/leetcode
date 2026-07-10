// Last updated: 10/07/2026, 21:44:27
1struct ListNode* oddEvenList(struct ListNode* head) {
2    if (head == NULL || head->next == NULL)
3        return head;
4
5    struct ListNode *odd = head;
6    struct ListNode *even = head->next;
7    struct ListNode *evenHead = even;
8
9    while (even != NULL && even->next != NULL) {
10        odd->next = even->next;
11        odd = odd->next;
12
13        even->next = odd->next;
14        even = even->next;
15    }
16
17    odd->next = evenHead;
18
19    return head;
20}