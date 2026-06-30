// Last updated: 30/06/2026, 22:42:32
1void merge(int* nums, int left, int mid, int right) {
2    int n1 = mid - left + 1;
3    int n2 = right - mid;
4
5    int L[n1], R[n2];
6
7    for (int i = 0; i < n1; i++)
8        L[i] = nums[left + i];
9    for (int i = 0; i < n2; i++)
10        R[i] = nums[mid + 1 + i];
11
12    int i = 0, j = 0, k = left;
13
14    while (i < n1 && j < n2) {
15        if (L[i] <= R[j])
16            nums[k++] = L[i++];
17        else
18            nums[k++] = R[j++];
19    }
20
21    while (i < n1)
22        nums[k++] = L[i++];
23
24    while (j < n2)
25        nums[k++] = R[j++];
26}
27
28void mergeSort(int* nums, int left, int right) {
29    if (left >= right)
30        return;
31
32    int mid = left + (right - left) / 2;
33
34    mergeSort(nums, left, mid);
35    mergeSort(nums, mid + 1, right);
36
37    merge(nums, left, mid, right);
38}
39
40int* sortArray(int* nums, int numsSize, int* returnSize) {
41    *returnSize = numsSize;
42
43    mergeSort(nums, 0, numsSize - 1);
44
45    return nums;
46}