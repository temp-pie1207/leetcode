// Last updated: 08/07/2026, 21:20:30
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     struct TreeNode *left;
6 *     struct TreeNode *right;
7 * };
8 */
9
10void dfs(struct TreeNode* root, int level, int *ans, int *returnSize)
11{
12    if(root == NULL)
13        return;
14
15    if(level == *returnSize)
16        ans[(*returnSize)++] = root->val;
17
18    dfs(root->right, level + 1, ans, returnSize);
19    dfs(root->left, level + 1, ans, returnSize);
20}
21
22int* rightSideView(struct TreeNode* root, int* returnSize)
23{
24    int *ans = (int*)malloc(100 * sizeof(int));
25    *returnSize = 0;
26
27    dfs(root, 0, ans, returnSize);
28
29    return ans;
30}