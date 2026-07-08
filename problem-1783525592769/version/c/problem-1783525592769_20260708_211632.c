// Last updated: 08/07/2026, 21:16:32
1void rotate(int* nums, int numsSize, int k) {
2    int temp[100000];
3    int i;
4
5    k = k % numsSize;
6
7    for(i = 0; i < numsSize; i++) {
8        temp[(i + k) % numsSize] = nums[i];
9    }
10
11    for(i = 0; i < numsSize; i++) {
12        nums[i] = temp[i];
13    }
14}