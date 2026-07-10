// Last updated: 10/07/2026, 13:52:41
1void moveZeroes(int* nums, int numsSize) {
2    int j = 0;
3    for (int i = 0; i < numsSize; i++) {
4        if (nums[i] != 0) {
5            nums[j++] = nums[i];
6        }
7    }
8    while (j < numsSize) {
9        nums[j++] = 0;
10    }
11}