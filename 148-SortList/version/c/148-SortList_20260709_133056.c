// Last updated: 09/07/2026, 13:30:56
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8
9struct ListNode* middle(struct ListNode* head)
10{
11    struct ListNode *slow = head;
12    struct ListNode *fast = head->next;
13
14    while(fast != NULL && fast->next != NULL)
15    {
16        slow = slow->next;
17        fast = fast->next->next;
18    }
19
20    return slow;
21}
22
23struct ListNode* merge(struct ListNode* l1, struct ListNode* l2)
24{
25    struct ListNode dummy;
26    struct ListNode *tail = &dummy;
27    dummy.next = NULL;
28
29    while(l1 != NULL && l2 != NULL)
30    {
31        if(l1->val <= l2->val)
32        {
33            tail->next = l1;
34            l1 = l1->next;
35        }
36        else
37        {
38            tail->next = l2;
39            l2 = l2->next;
40        }
41        tail = tail->next;
42    }
43
44    if(l1 != NULL)
45        tail->next = l1;
46    else
47        tail->next = l2;
48
49    return dummy.next;
50}
51
52struct ListNode* sortList(struct ListNode* head)
53{
54    if(head == NULL || head->next == NULL)
55        return head;
56
57    struct ListNode *mid = middle(head);
58    struct ListNode *right = mid->next;
59    mid->next = NULL;
60
61    struct ListNode *left = sortList(head);
62    right = sortList(right);
63
64    return merge(left, right);
65}