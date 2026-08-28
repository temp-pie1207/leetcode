// Last updated: 28/08/2026, 14:50:10
1int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
2    int **matrix = malloc(n * sizeof(int*));
3
4    for (int i = 0; i < n; i++)
5        matrix[i] = malloc(n * sizeof(int));
6
7    *returnSize = n;
8
9    *returnColumnSizes = malloc(n * sizeof(int));
10    for (int i = 0; i < n; i++)
11        (*returnColumnSizes)[i] = n;
12
13    int top = 0, bottom = n - 1;
14    int left = 0, right = n - 1;
15    int num = 1;
16
17    while (top <= bottom && left <= right) {
18
19        for (int i = left; i <= right; i++)
20            matrix[top][i] = num++;
21
22        top++;
23
24        for (int i = top; i <= bottom; i++)
25            matrix[i][right] = num++;
26
27        right--;
28
29        if (top <= bottom) {
30            for (int i = right; i >= left; i--)
31                matrix[bottom][i] = num++;
32
33            bottom--;
34        }
35
36        if (left <= right) {
37            for (int i = bottom; i >= top; i--)
38                matrix[i][left] = num++;
39
40            left++;
41        }
42    }
43
44    return matrix;
45}