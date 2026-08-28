// Last updated: 28/08/2026, 14:54:55
1int* getRow(int rowIndex, int* returnSize) {
2    int *row = malloc((rowIndex + 1) * sizeof(int));
3
4    for (int i = 0; i <= rowIndex; i++)
5        row[i] = 1;
6
7    for (int i = 2; i <= rowIndex; i++) {
8        for (int j = i - 1; j > 0; j--) {
9            row[j] = row[j] + row[j - 1];
10        }
11    }
12
13    *returnSize = rowIndex + 1;
14
15    return row;
16}