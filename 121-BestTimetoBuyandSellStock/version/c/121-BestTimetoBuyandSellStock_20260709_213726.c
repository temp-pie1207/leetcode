// Last updated: 09/07/2026, 21:37:26
1int maxProfit(int* prices, int pricesSize) {
2    int minPrice = prices[0];
3    int maxProfit = 0;
4
5    for (int i = 1; i < pricesSize; i++) {
6        if (prices[i] < minPrice) {
7            minPrice = prices[i];
8        } else {
9            int profit = prices[i] - minPrice;
10            if (profit > maxProfit) {
11                maxProfit = profit;
12            }
13        }
14    }
15
16    return maxProfit;
17}