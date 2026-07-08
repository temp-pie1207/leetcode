// Last updated: 08/07/2026, 16:21:59
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     struct TreeNode *left;
6 *     struct TreeNode *right;
7 * };
8 */
9
10void post(struct TreeNode* root, int *arr, int *index)
11{
12    if(root == NULL)
13        return;
14
15    post(root->left, arr, index);
16    post(root->right, arr, index);
17    arr[(*index)++] = root->val;
18}
19
20int* postorderTraversal(struct TreeNode* root, int* returnSize)
21{
22    int *arr = (int *)malloc(100 * sizeof(int));
23    int index = 0;
24
25    post(root, arr, &index);
26
27    *returnSize = index;
28
29    return arr;
30}