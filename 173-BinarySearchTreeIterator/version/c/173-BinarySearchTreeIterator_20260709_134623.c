// Last updated: 09/07/2026, 13:46:23
1int majorityElement(int* nums, int numsSize) {
2    int c = nums[0];
3    int count = 1;
4
5    for(int i = 1; i < numsSize; i++)
6    {
7        if(count == 0)
8        {
9            c = nums[i];
10            count = 1;
11        }
12        else if(nums[i] == c)
13        {
14            count++;
15        }
16        else
17        {
18            count--;
19        }
20    }
21
22    return c;
23}