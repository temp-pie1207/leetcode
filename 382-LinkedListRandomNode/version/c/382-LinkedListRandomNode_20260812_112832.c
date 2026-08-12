// Last updated: 12/08/2026, 11:28:32
1#include <stdlib.h>
2#include <time.h>
3
4typedef struct {
5    struct ListNode *head;
6} Solution;
7
8Solution* solutionCreate(struct ListNode* head) {
9    Solution* obj = malloc(sizeof(Solution));
10    obj->head = head;
11    return obj;
12}
13
14int solutionGetRandom(Solution* obj) {
15    struct ListNode* curr = obj->head;
16    int ans = curr->val;
17    int i = 1;
18
19    while (curr != NULL) {
20        if (rand() % i == 0)
21            ans = curr->val;
22
23        curr = curr->next;
24        i++;
25    }
26
27    return ans;
28}
29
30void solutionFree(Solution* obj) {
31    free(obj);
32}