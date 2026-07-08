// Last updated: 08/07/2026, 16:22:58
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8
9void reorderList(struct ListNode* head) {
10
11    if (head == NULL || head->next == NULL)
12        return;
13
14    
15    struct ListNode *slow = head;
16    struct ListNode *fast = head;
17
18    while (fast->next && fast->next->next) {
19        slow = slow->next;
20        fast = fast->next->next;
21    }
22
23
24    struct ListNode *prev = NULL;
25    struct ListNode *curr = slow->next;
26    struct ListNode *next;
27
28    slow->next = NULL;
29
30    while (curr) {
31        next = curr->next;
32        curr->next = prev;
33        prev = curr;
34        curr = next;
35    }
36
37
38    struct ListNode *first = head;
39    struct ListNode *second = prev;
40
41    while (second) {
42        struct ListNode *t1 = first->next;
43        struct ListNode *t2 = second->next;
44
45        first->next = second;
46        second->next = t1;
47
48        first = t1;
49        second = t2;
50    }
51}