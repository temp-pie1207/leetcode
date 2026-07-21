// Last updated: 21/07/2026, 15:54:11
1int findNumbers(int* nums, int numsSize) {
2    int even=0;
3    
4    for(int i =0;i<numsSize;i++){
5        int hpp = nums[i];
6        int count =0;
7        while(hpp!=0){
8        
9         hpp/=10;
10         count++; 
11           
12        }
13        if(count%2==0){
14            even ++;
15        }
16    }
17        return even;
18    
19}