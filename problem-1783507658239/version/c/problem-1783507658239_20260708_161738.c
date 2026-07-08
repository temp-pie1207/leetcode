// Last updated: 08/07/2026, 16:17:38
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     struct TreeNode *left;
6 *     struct TreeNode *right;
7 * };
8 */
9
10void dfs(struct TreeNode* root, int level, int** ans, int* col) {
11    if (root == NULL)
12        return;
13
14    ans[level][col[level]++] = root->val;
15
16    dfs(root->left, level + 1, ans, col);
17    dfs(root->right, level + 1, ans, col);
18}
19
20int height(struct TreeNode* root) {
21    if (root == NULL)
22        return 0;
23
24    int l = height(root->left);
25    int r = height(root->right);
26
27    return (l > r ? l : r) + 1;
28}
29
30int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
31
32    *returnSize = height(root);
33
34    if (*returnSize == 0) {
35        *returnColumnSizes = NULL;
36        return NULL;
37    }
38
39    int **ans = (int **)malloc((*returnSize) * sizeof(int *));
40    *returnColumnSizes = (int *)calloc(*returnSize, sizeof(int));
41
42    for (int i = 0; i < *returnSize; i++)
43        ans[i] = (int *)malloc(2001 * sizeof(int));
44
45    dfs(root, 0, ans, *returnColumnSizes);
46
47    return ans;
48}