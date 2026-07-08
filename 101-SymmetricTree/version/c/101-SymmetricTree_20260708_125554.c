// Last updated: 08/07/2026, 12:55:54
1bool mirror(struct TreeNode* left, struct TreeNode* right) {
2    if (left == NULL && right == NULL)
3        return true;
4
5    if (left == NULL || right == NULL)
6        return false;
7
8    if (left->val != right->val)
9        return false;
10
11    return mirror(left->left, right->right) &&
12           mirror(left->right, right->left);
13}
14
15bool isSymmetric(struct TreeNode* root) {
16    if (root == NULL)
17        return true;
18
19    return mirror(root->left, root->right);
20}