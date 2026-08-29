// Last updated: 29/08/2026, 20:08:02
1int minBishopMoves(int* source, int sourceSize, int* target, int targetSize) {
2    int r1=source[0],c1=source[1];
3    int r2=target[0],c2=target[1];
4    if (r1==r2 & c1==c2)
5        return 0;
6    if(abs(r1-r2)==abs(c1-c2))
7        return 1;
8    if((r1+c1)%2==(r2+c2)%2)
9        return 2;
10    return -1;
11}