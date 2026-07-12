// Last updated: 12/07/2026, 16:25:18
1bool uniformArray(int* nums1, int nums1Size) {
2    int even = 0, odd = 0;
3
4    for (int i = 0; i < nums1Size; i++) {
5        if (nums1[i] % 2 == 0)
6            even++;
7        else
8            odd++;
9    }
10
11    if (even == nums1Size || odd == nums1Size)
12        return true;
13
14    if (even > 0 && odd > 0)
15        return true;
16
17    return false;
18}