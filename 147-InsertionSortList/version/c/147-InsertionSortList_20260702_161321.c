// Last updated: 02/07/2026, 16:13:21
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8struct ListNode* insertionSortList(struct ListNode* head) {
9    struct ListNode *ptr=head;
10    struct ListNode *ptr1=head;
11    int temp;
12    while(ptr!=NULL){ptr1=ptr->next;
13        while(ptr1!=NULL){
14            if (ptr->val>ptr1->val){
15                temp=ptr->val;
16                ptr->val=ptr1->val;
17                ptr1->val=temp;
18            }
19            ptr1=ptr1->next;
20        }
21        ptr=ptr->next;
22    }
23    return head;
24}