// Last updated: 10/07/2026, 13:49:05
1void flatten(struct TreeNode* root) {
2    struct TreeNode *ptr = root;
3
4    while (ptr != NULL) {
5        if (ptr->left != NULL) {
6            struct TreeNode *prev = ptr->left;
7            while (prev->right != NULL) {
8                prev = prev->right;
9            }
10            prev->right = ptr->right;  
11            ptr->right = ptr->left;
12            ptr->left = NULL;
13        }  
14        ptr = ptr->right;
15    }
16}