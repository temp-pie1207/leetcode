// Last updated: 05/07/2026, 13:40:58
1bool present[10001];
2
3int numComponents(struct ListNode* head, int* nums, int numsSize) {
4    int i, count = 0;
5    for (i = 0; i < numsSize; i++)
6        present[nums[i]] = true;
7    while (head) {
8        if (present[head->val] &&
9            (head->next == NULL || !present[head->next->val]))
10            count++;
11        head = head->next;
12    }
13    for (i = 0; i < numsSize; i++)
14        present[nums[i]] = false;
15
16    return count;
17}