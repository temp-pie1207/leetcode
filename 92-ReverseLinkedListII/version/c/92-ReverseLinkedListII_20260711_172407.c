// Last updated: 11/07/2026, 17:24:07
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
9    int arr[500];
10    int n=0;
11    struct ListNode *ptr=head;
12    while(ptr!=NULL){
13        arr[n++]=ptr->val;
14        ptr=ptr->next;
15    }
16    int i=left-1;
17    int j=right-1;
18    while(i<j){
19        int temp= arr[i];
20        arr[i] = arr[j];
21        arr[j]= temp;
22        i++;
23        j--;
24    }
25    int l=0;
26    ptr=head;
27    while(ptr!=NULL){
28        ptr->val=arr[l++];
29        ptr=ptr->next;
30    }
31    return head;
32}