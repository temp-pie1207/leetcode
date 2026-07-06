// Last updated: 06/07/2026, 15:00:01
1#include <stdio.h>
2#include <stdlib.h>
3#include <string.h>
4
5void dfs(struct TreeNode* root, char* path, char** ans, int* size) {
6    char temp[1000];
7
8    if (strlen(path) == 0)
9        sprintf(temp, "%d", root->val);
10    else
11        sprintf(temp, "%s->%d", path, root->val);
12
13    if (!root->left && !root->right) {
14        ans[*size] = (char*)malloc(strlen(temp) + 1);
15        strcpy(ans[*size], temp);
16        (*size)++;
17        return;
18    }
19
20    if (root->left)
21        dfs(root->left, temp, ans, size);
22
23    if (root->right)
24        dfs(root->right, temp, ans, size);
25}
26
27char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
28    char** ans = (char**)malloc(100 * sizeof(char*));
29    *returnSize = 0;
30
31    if (root)
32        dfs(root, "", ans, returnSize);
33
34    return ans;
35}