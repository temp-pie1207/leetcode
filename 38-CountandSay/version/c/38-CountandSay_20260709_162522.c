// Last updated: 09/07/2026, 16:25:22
1int count = 0;
2int ans = 0;
3
4void inorder(struct TreeNode* root, int k) {
5    if (root == NULL) return;
6
7    inorder(root->left, k);
8
9    count++;
10    if (count == k) {
11        ans = root->val;
12        return;
13    }
14
15    inorder(root->right, k);
16}
17
18int kthSmallest(struct TreeNode* root, int k) {
19    count = 0;
20    ans = 0;
21    inorder(root, k);
22    return ans;
23}