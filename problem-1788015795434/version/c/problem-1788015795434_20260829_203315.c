// Last updated: 29/08/2026, 20:33:15
1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4#include<stdlib.h>
5char** largestString(int* nums, int numsSize, int* returnSize) {
6    char** ans=malloc(numsSize*sizeof(char*));
7    *returnSize=numsSize;
8    for(int k=0;k<numsSize;k++){
9        int x=nums[k];
10        int z=x/(1<<25);
11        int rem=x%(1<<25);
12        int len=z;
13        for(int i=24;i>=0;i--){
14            if((rem>>i)&1){
15                len++;
16            }
17        }
18          ans[k]=malloc((len+1)*sizeof(char));
19        int p=0;
20        while(z>0){
21            ans[k][p++]='z';
22            z--;
23        }
24        for(int i=24;i>=0;i--){
25            if((rem>>i)&1){
26                ans[k][p++]='a'+i;
27            }
28        }
29        ans[k][p]='\0';
30    }
31    return ans;
32}