// Last updated: 08/07/2026, 17:47:09
1int findMin(int* nums, int numsSize) {
2    int min=nums[0];
3    for(int i =1;i<numsSize;i++){
4        if (nums[i]<min){
5            min=nums[i];
6        }
7    }
8    return min;
9    
10}