// Last updated: 08/07/2026, 16:20:29
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8
9struct ListNode *detectCycle(struct ListNode *head) {
10
11    struct ListNode *slow = head;
12    struct ListNode *fast = head;
13
14    while (fast != NULL && fast->next != NULL) {
15        slow = slow->next;
16        fast = fast->next->next;
17
18        if (slow == fast) {
19            slow = head;
20
21            while (slow != fast) {
22                slow = slow->next;
23                fast = fast->next;
24            }
25
26            return slow;
27        }
28    }
29
30    return NULL;
31}