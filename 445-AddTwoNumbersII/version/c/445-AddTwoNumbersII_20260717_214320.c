// Last updated: 17/07/2026, 21:43:20
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8
9struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
10    int s1[101], s2[101];
11    int top1 = -1, top2 = -1;
12
13    while (l1) {
14        s1[++top1] = l1->val;
15        l1 = l1->next;
16    }
17
18    while (l2) {
19        s2[++top2] = l2->val;
20        l2 = l2->next;
21    }
22
23    int carry = 0;
24    struct ListNode *head = NULL;
25
26    while (top1 >= 0 || top2 >= 0 || carry) {
27        int sum = carry;
28
29        if (top1 >= 0)
30            sum += s1[top1--];
31
32        if (top2 >= 0)
33            sum += s2[top2--];
34
35        carry = sum / 10;
36
37        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
38        node->val = sum % 10;
39        node->next = head;
40        head = node;
41    }
42
43    return head;
44}