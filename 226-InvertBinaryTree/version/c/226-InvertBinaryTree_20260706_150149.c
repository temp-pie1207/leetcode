// Last updated: 06/07/2026, 15:01:49
1struct TreeNode* build(int* nums, int left, int right) {
2    if (left > right)
3        return NULL;
4
5    int maxIndex = left;
6    for (int i = left + 1; i <= right; i++) {
7        if (nums[i] > nums[maxIndex])
8            maxIndex = i;
9    }
10
11    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
12    root->val = nums[maxIndex];
13
14    root->left = build(nums, left, maxIndex - 1);
15    root->right = build(nums, maxIndex + 1, right);
16
17    return root;
18}
19
20struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
21    return build(nums, 0, numsSize - 1);
22}