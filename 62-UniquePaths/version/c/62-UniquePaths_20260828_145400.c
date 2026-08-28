// Last updated: 28/08/2026, 14:54:00
1int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
2    if (root == NULL) {
3        *returnSize = 0;
4        *returnColumnSizes = NULL;
5        return NULL;
6    }
7
8    int** result = malloc(2000 * sizeof(int*));
9    *returnColumnSizes = malloc(2000 * sizeof(int));
10
11    struct TreeNode* queue[2000];
12    int front = 0, rear = 0;
13
14    queue[rear++] = root;
15
16    int levels = 0;
17
18    while (front < rear) {
19        int size = rear - front;
20
21        result[levels] = malloc(size * sizeof(int));
22        (*returnColumnSizes)[levels] = size;
23
24        for (int i = 0; i < size; i++) {
25            struct TreeNode* node = queue[front++];
26
27            result[levels][i] = node->val;
28
29            if (node->left)
30                queue[rear++] = node->left;
31
32            if (node->right)
33                queue[rear++] = node->right;
34        }
35
36        levels++;
37    }
38
39    for (int i = 0; i < levels / 2; i++) {
40        int* temp = result[i];
41        result[i] = result[levels - 1 - i];
42        result[levels - 1 - i] = temp;
43
44        int tempSize = (*returnColumnSizes)[i];
45        (*returnColumnSizes)[i] = (*returnColumnSizes)[levels - 1 - i];
46        (*returnColumnSizes)[levels - 1 - i] = tempSize;
47    }
48
49    *returnSize = levels;
50
51    return result;
52}