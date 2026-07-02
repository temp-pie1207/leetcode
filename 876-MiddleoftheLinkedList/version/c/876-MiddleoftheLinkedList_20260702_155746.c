// Last updated: 02/07/2026, 15:57:46
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8struct ListNode* middleNode(struct ListNode* head) {
9    struct ListNode *ptr=head;
10    struct ListNode *ptr1=head;
11    while(ptr1 !=NULL && ptr1->next !=NULL){
12        ptr=ptr->next;
13        ptr1=ptr1->next->next;
14    }
15    return ptr;
16}