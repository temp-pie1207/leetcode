// Last updated: 05/07/2026, 14:10:46
1int height(struct TreeNode* root) {
2    if (root == NULL)
3        return 0;
4    int left = height(root->left);
5    if (left == -1) return -1;
6    int right = height(root->right);
7    if (right == -1) return -1;
8    if (abs(left - right) > 1)
9        return -1;
10    return 1 + (left > right ? left : right);
11}
12bool isBalanced(struct TreeNode* root) {
13    return height(root) != -1;
14}