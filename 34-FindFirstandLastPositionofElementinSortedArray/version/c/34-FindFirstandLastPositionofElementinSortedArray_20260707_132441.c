// Last updated: 07/07/2026, 13:24:41
1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
5    * returnSize=2;
6    int *arr=(int *)malloc(2*sizeof(int));
7    int i=0;
8    int j=numsSize-1;
9    arr[0]=-1;
10    arr[1]=-1;
11    for(i;i<numsSize;i++){
12        if(nums[i]==target){
13            arr[0]=i;
14            break;
15        }
16        else arr[0]=-1;
17    }
18    for(j;j>=0;j--){
19        if(nums[j]==target){
20            arr[1]=j;
21            break;
22        }
23        else arr[1]=-1;
24    }
25    return arr;
26}