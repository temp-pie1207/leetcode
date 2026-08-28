// Last updated: 28/08/2026, 14:50:29
1int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
2    int **matrix = malloc(n * sizeof(int*));
3    for (int i = 0; i < n; i++)
4        matrix[i] = malloc(n * sizeof(int));
5    *returnSize = n;
6    *returnColumnSizes = malloc(n * sizeof(int));
7    for (int i = 0; i < n; i++)
8        (*returnColumnSizes)[i] = n;
9    int top = 0, bottom = n - 1;
10    int left = 0, right = n - 1;
11    int num = 1;
12    while (top <= bottom && left <= right) {
13        for (int i = left; i <= right; i++)
14            matrix[top][i] = num++;
15        top++;
16        for (int i = top; i <= bottom; i++)
17            matrix[i][right] = num++;
18        right--;
19        if (top <= bottom) {
20            for (int i = right; i >= left; i--)
21                matrix[bottom][i] = num++;
22            bottom--;
23        }
24        if (left <= right) {
25            for (int i = bottom; i >= top; i--)
26                matrix[i][left] = num++;
27            left++;
28        }
29    }
30    return matrix;
31}