// Last updated: 08/07/2026, 16:17:14
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     struct TreeNode *left;
6 *     struct TreeNode *right;
7 * };
8 */
9
10int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
11
12    if (root == NULL) {
13        *returnSize = 0;
14        *returnColumnSizes = NULL;
15        return NULL;
16    }
17
18    struct TreeNode* q[2001];
19    int front = 0, rear = 0;
20
21    q[rear++] = root;
22
23    int **ans = (int **)malloc(2001 * sizeof(int *));
24    *returnColumnSizes = (int *)malloc(2001 * sizeof(int));
25
26    *returnSize = 0;
27
28    while (front < rear) {
29
30        int size = rear - front;
31
32        ans[*returnSize] = (int *)malloc(size * sizeof(int));
33        (*returnColumnSizes)[*returnSize] = size;
34
35        for (int i = 0; i < size; i++) {
36
37            struct TreeNode *temp = q[front++];
38
39            ans[*returnSize][i] = temp->val;
40
41            if (temp->left)
42                q[rear++] = temp->left;
43
44            if (temp->right)
45                q[rear++] = temp->right;
46        }
47
48        (*returnSize)++;
49    }
50
51    return ans;
52}