// Last updated: 06/07/2026, 14:58:36
1struct TreeNode* invertTree(struct TreeNode* root) {
2    if (root == NULL)
3        return NULL;
4
5    struct TreeNode* temp = root->left;
6    root->left = root->right;
7    root->right = temp;
8
9    invertTree(root->left);
10    invertTree(root->right);
11
12    return root;
13}