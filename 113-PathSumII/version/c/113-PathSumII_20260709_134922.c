// Last updated: 09/07/2026, 13:49:22
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     struct TreeNode *left;
6 *     struct TreeNode *right;
7 * };
8 */
9
10int **ans;
11int *colSize;
12int path[5000];
13int count;
14
15void dfs(struct TreeNode *root, int sum, int level)
16{
17    if(root == NULL)
18        return;
19
20    path[level] = root->val;
21    sum -= root->val;
22
23    if(root->left == NULL && root->right == NULL)
24    {
25        if(sum == 0)
26        {
27            ans[count] = (int *)malloc((level + 1) * sizeof(int));
28
29            for(int i = 0; i <= level; i++)
30                ans[count][i] = path[i];
31
32            colSize[count] = level + 1;
33            count++;
34        }
35        return;
36    }
37
38    dfs(root->left, sum, level + 1);
39    dfs(root->right, sum, level + 1);
40}
41
42int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes)
43{
44    ans = (int **)malloc(5000 * sizeof(int *));
45    colSize = (int *)malloc(5000 * sizeof(int));
46
47    count = 0;
48
49    dfs(root, targetSum, 0);
50
51    *returnSize = count;
52    *returnColumnSizes = colSize;
53
54    return ans;
55}