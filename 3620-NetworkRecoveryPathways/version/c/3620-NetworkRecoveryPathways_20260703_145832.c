// Last updated: 03/07/2026, 14:58:32
1#include <stdlib.h>
2#include <stdbool.h>
3#include <limits.h>
4
5typedef struct Edge {
6    int to;
7    int cost;
8    struct Edge *next;
9} Edge;
10
11long long INF = (1LL << 60);
12
13int findMaxPathScore(int** edges, int edgesSize, int* edgesColSize,
14                     bool* online, int onlineSize, long long k) {
15    int n = onlineSize;
16
17    Edge **graph = (Edge **)calloc(n, sizeof(Edge *));
18    int *indeg = (int *)calloc(n, sizeof(int));
19
20    int maxCost = -1;
21
22    // Build graph
23    for (int i = 0; i < edgesSize; i++) {
24        int u = edges[i][0];
25        int v = edges[i][1];
26        int c = edges[i][2];
27
28        Edge *e = (Edge *)malloc(sizeof(Edge));
29        e->to = v;
30        e->cost = c;
31        e->next = graph[u];
32        graph[u] = e;
33
34        indeg[v]++;
35        if (c > maxCost) maxCost = c;
36    }
37
38    // Topological order (Kahn)
39    int *queue = (int *)malloc(sizeof(int) * n);
40    int *topo = (int *)malloc(sizeof(int) * n);
41
42    int front = 0, back = 0;
43    int *deg = (int *)malloc(sizeof(int) * n);
44    for (int i = 0; i < n; i++) deg[i] = indeg[i];
45
46    for (int i = 0; i < n; i++)
47        if (deg[i] == 0)
48            queue[back++] = i;
49
50    int idx = 0;
51    while (front < back) {
52        int u = queue[front++];
53        topo[idx++] = u;
54
55        for (Edge *e = graph[u]; e; e = e->next) {
56            if (--deg[e->to] == 0)
57                queue[back++] = e->to;
58        }
59    }
60
61    long long *dist = (long long *)malloc(sizeof(long long) * n);
62
63    int lo = 0, hi = maxCost, ans = -1;
64
65    while (lo <= hi) {
66        int mid = lo + (hi - lo) / 2;
67
68        for (int i = 0; i < n; i++)
69            dist[i] = INF;
70        dist[0] = 0;
71
72        for (int i = 0; i < n; i++) {
73            int u = topo[i];
74            if (dist[u] == INF) continue;
75
76            // intermediate offline nodes cannot be used
77            if (u != 0 && u != n - 1 && !online[u]) continue;
78
79            for (Edge *e = graph[u]; e; e = e->next) {
80                if (e->cost < mid) continue;
81
82                int v = e->to;
83
84                if (v != n - 1 && v != 0 && !online[v]) continue;
85
86                if (dist[u] + e->cost < dist[v])
87                    dist[v] = dist[u] + e->cost;
88            }
89        }
90
91        if (dist[n - 1] <= k) {
92            ans = mid;
93            lo = mid + 1;
94        } else {
95            hi = mid - 1;
96        }
97    }
98
99    // Free memory
100    for (int i = 0; i < n; i++) {
101        Edge *cur = graph[i];
102        while (cur) {
103            Edge *tmp = cur;
104            cur = cur->next;
105            free(tmp);
106        }
107    }
108
109    free(graph);
110    free(indeg);
111    free(queue);
112    free(topo);
113    free(deg);
114    free(dist);
115
116    return ans;
117}