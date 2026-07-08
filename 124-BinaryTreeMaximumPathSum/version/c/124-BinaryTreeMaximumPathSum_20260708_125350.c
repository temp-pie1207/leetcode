// Last updated: 08/07/2026, 12:53:50
1#include <limits.h>
2int ans;
3int max(int a, int b) {
4    return a > b ? a : b;
5}
6int dfs(struct TreeNode* root) {
7    if (root == NULL)
8        return 0;
9    int left = max(0, dfs(root->left));
10    int right = max(0, dfs(root->right));
11    ans = max(ans, root->val + left + right);
12   return root->val + max(left, right);
13}
14int maxPathSum(struct TreeNode* root) {
15    ans = INT_MIN;
16    dfs(root);
17    return ans;
18}