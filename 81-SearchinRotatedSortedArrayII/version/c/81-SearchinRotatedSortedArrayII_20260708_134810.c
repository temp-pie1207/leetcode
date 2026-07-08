// Last updated: 08/07/2026, 13:48:10
1bool search(int* nums, int numsSize, int target) {
2    for (int i = 0; i < numsSize; i++) {
3        if (nums[i] == target)
4            return true;
5    }
6    return false;
7}