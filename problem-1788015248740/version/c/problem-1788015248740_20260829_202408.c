// Last updated: 29/08/2026, 20:24:08
1
2int gcd(int a,int b){
3    while(b){
4        int t=a%b;
5        a=b;
6        b=t;
7        
8    }
9    return a;
10}
11int maxValidSplits(int* nums, int numsSize) {
12    int ans=0;
13    for(int r=-1;r<numsSize;r++){
14        int m=numsSize-(r!=-1);
15        if(m<2)
16            continue;
17        int arr[m];
18        int k=0;
19        for(int i=0;i<numsSize;i++){
20           if(i!=r)
21               arr[k++]=nums[i];    
22        }
23        int prefix[m];
24        int suffix[m];
25        prefix[0]=arr[0];
26        for(int i=1;i<m;i++)
27            prefix[i]=gcd(prefix[i-1],arr[i]);
28        suffix[m-1]=arr[m-1];
29        for(int i=m-2;i>=0;i--)
30            suffix[i]=gcd(suffix[i+1],arr[i]);
31        int c=0;
32        for(int i=0;i<m-1;i++){
33            if(prefix[i]==suffix[i+1])
34                c++;
35        }
36        if(c>ans)
37            ans=c;
38        
39          
40            
41        
42       
43    }
44    return ans;
45   
46}