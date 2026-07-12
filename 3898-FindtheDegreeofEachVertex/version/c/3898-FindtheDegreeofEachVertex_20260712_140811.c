// Last updated: 12/07/2026, 14:08:11
1int* findDegrees(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
2    *returnSize = matrixSize;
3
4    int *ans = (int *)malloc(matrixSize * sizeof(int));
5
6    for (int i = 0; i < matrixSize; i++) {
7        ans[i] = 0;
8
9        for (int j = 0; j < matrixSize; j++) {
10            if (matrix[i][j] == 1)
11                ans[i]++;
12        }
13    }
14
15    return ans;
16}