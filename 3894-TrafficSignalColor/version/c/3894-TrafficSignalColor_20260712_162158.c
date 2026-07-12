// Last updated: 12/07/2026, 16:21:58
1char* trafficSignal(int timer) {
2    if (timer == 0)
3        return "Green";
4    else if (timer == 30)
5        return "Orange";
6    else if (timer > 30 && timer <= 90)
7        return "Red";
8    else
9        return "Invalid";
10}