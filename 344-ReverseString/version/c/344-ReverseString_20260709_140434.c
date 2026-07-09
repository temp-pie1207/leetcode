// Last updated: 09/07/2026, 14:04:34
1bool isPerfectSquare(int num) {
2    long left = 1, right = num;
3
4    while (left <= right) {
5        long mid = left + (right - left) / 2;
6        long square = mid * mid;
7
8        if (square == num)
9            return true;
10        else if (square < num)
11            left = mid + 1;
12        else
13            right = mid - 1;
14    }
15
16    return false;
17}