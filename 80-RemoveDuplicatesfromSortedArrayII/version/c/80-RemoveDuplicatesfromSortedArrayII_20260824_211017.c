// Last updated: 24/08/2026, 21:10:17
1int removeDuplicates(int* nums, int numsSize) {
2    int count=1;
3    int k=1;
4    if(numsSize<=2) return numsSize;
5    for(int i=1;i<numsSize;i++){
6        if(nums[i]==nums[i-1]) count++;
7        else count=1;
8        if(count<=2){
9            nums[k]=nums[i];
10            k++;
11        } 
12    }
13    return k;
14}