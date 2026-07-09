// Last updated: 09/07/2026, 23:06:57
1void deleteNode(struct ListNode* node) {
2    node->val = node->next->val;
3    node->next = node->next->next;
4}