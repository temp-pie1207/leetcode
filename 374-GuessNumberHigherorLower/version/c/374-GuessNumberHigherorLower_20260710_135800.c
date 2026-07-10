// Last updated: 10/07/2026, 13:58:00
1int guess(int num);
2int guessNumber(int n) {
3    int low = 1, high = n;
4
5    while (low <= high) {
6        int mid = low + (high - low) / 2;
7
8        if (guess(mid) == 0)
9            return mid;
10        else if (guess(mid) == -1)
11            high = mid - 1;
12        else
13            low = mid + 1;
14    }
15
16    return -1;
17}