// Last updated: 02/07/2026, 21:27:53
1#include <stdlib.h>
2
3int max(int a, int b) {
4    return a > b ? a : b;
5}
6
7int largestRectangleArea(int* heights, int n) {
8    int stack[n + 1];
9    int top = -1;
10    int maxArea = 0;
11
12    for (int i = 0; i <= n; i++) {
13        int h = (i == n) ? 0 : heights[i];
14
15        while (top >= 0 && h < heights[stack[top]]) {
16            int height = heights[stack[top--]];
17            int width = (top < 0) ? i : i - stack[top] - 1;
18            maxArea = max(maxArea, height * width);
19        }
20        stack[++top] = i;
21    }
22    return maxArea;
23}
24
25int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
26    if (matrixSize == 0) return 0;
27
28    int rows = matrixSize;
29    int cols = matrixColSize[0];
30
31    int heights[cols];
32    for (int j = 0; j < cols; j++)
33        heights[j] = 0;
34
35    int ans = 0;
36
37    for (int i = 0; i < rows; i++) {
38        for (int j = 0; j < cols; j++) {
39            if (matrix[i][j] == '1')
40                heights[j] += 1;
41            else
42                heights[j] = 0;
43        }
44        ans = max(ans, largestRectangleArea(heights, cols));
45    }
46
47    return ans;
48}