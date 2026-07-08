// Last updated: 08/07/2026, 17:52:39
1int findMin(int* nums, int numsSize) {
2
3    int min=nums[0];
4    for(int i=1;i<numsSize;i++){
5        if (nums[i]<min){
6            min=nums[i];
7        }
8    }
9    return min;
10    
11}