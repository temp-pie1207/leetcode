// Last updated: 08/07/2026, 21:23:39
1#define MAX 100
2
3typedef struct {
4    int s1[MAX];
5    int s2[MAX];
6    int top1;
7    int top2;
8} MyQueue;
9
10MyQueue* myQueueCreate() {
11    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
12    q->top1 = -1;
13    q->top2 = -1;
14    return q;
15}
16
17void myQueuePush(MyQueue* obj, int x) {
18    obj->s1[++obj->top1] = x;
19}
20
21int myQueuePop(MyQueue* obj) {
22    if (obj->top2 == -1) {
23        while (obj->top1 != -1) {
24            obj->s2[++obj->top2] = obj->s1[obj->top1--];
25        }
26    }
27    return obj->s2[obj->top2--];
28}
29
30int myQueuePeek(MyQueue* obj) {
31    if (obj->top2 == -1) {
32        while (obj->top1 != -1) {
33            obj->s2[++obj->top2] = obj->s1[obj->top1--];
34        }
35    }
36    return obj->s2[obj->top2];
37}
38
39bool myQueueEmpty(MyQueue* obj) {
40    return (obj->top1 == -1 && obj->top2 == -1);
41}
42
43void myQueueFree(MyQueue* obj) {
44    free(obj);
45}