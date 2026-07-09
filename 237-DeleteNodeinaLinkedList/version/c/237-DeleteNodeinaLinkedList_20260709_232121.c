// Last updated: 09/07/2026, 23:21:21
1bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
2    for (int i = 0; i < matrixSize; i++) {
3        for (int j = 0; j < matrixColSize[0]; j++) {
4            if (matrix[i][j] == target) {
5                return true;
6            }
7        }
8    }
9    return false;
10}