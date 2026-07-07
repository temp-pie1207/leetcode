// Last updated: 07/07/2026, 13:09:54
1int search(int* nums, int numsSize, int target) {
2    int found=0;
3    int pos;
4    for(int i=0;i<numsSize;i++){
5        if(nums[i]==target){
6            found=1;
7            pos=i;
8        }
9    }
10    if(found==1){
11    return pos;}
12    else return -1;
13}