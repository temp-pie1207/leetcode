// Last updated: 03/07/2026, 15:05:21
1bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
2    int rows = matrixSize;
3    int cols = matrixColSize[0];
4
5    int left = 0, right = rows * cols - 1;
6
7    while (left <= right) {
8        int mid = left + (right - left) / 2;
9
10        int value = matrix[mid / cols][mid % cols];
11
12        if (value == target)
13            return true;
14        else if (value < target)
15            left = mid + 1;
16        else
17            right = mid - 1;
18    }
19
20    return false;
21}