// Last updated: 29/08/2026, 21:05:21
1#include <stdlib.h>
2
3int gcd(int a, int b) {
4    while (b) {
5        int t = a % b;
6        a = b;
7        b = t;
8    }
9    return a;
10}
11
12int rangeGcd(int **st, int *lg, int l, int r) {
13    if (l > r)
14        return 0;
15
16    int k = lg[r - l + 1];
17
18    return gcd(
19        st[k][l],
20        st[k][r - (1 << k) + 1]
21    );
22}
23
24int countAsc(int *a, int v, int l, int r) {
25    if (l > r)
26        return 0;
27
28    int lo = l, hi = r + 1;
29
30    while (lo < hi) {
31        int mid = lo + (hi - lo) / 2;
32
33        if (a[mid] < v)
34            lo = mid + 1;
35        else
36            hi = mid;
37    }
38
39    int first = lo;
40
41    if (first > r || a[first] != v)
42        return 0;
43
44    lo = first;
45    hi = r + 1;
46
47    while (lo < hi) {
48        int mid = lo + (hi - lo) / 2;
49
50        if (a[mid] <= v)
51            lo = mid + 1;
52        else
53            hi = mid;
54    }
55
56    return lo - first;
57}
58
59int countDesc(int *a, int v, int l, int r) {
60    if (l > r)
61        return 0;
62
63    int lo = l, hi = r + 1;
64
65    while (lo < hi) {
66        int mid = lo + (hi - lo) / 2;
67
68        if (a[mid] > v)
69            lo = mid + 1;
70        else
71            hi = mid;
72    }
73
74    int first = lo;
75
76    if (first > r || a[first] != v)
77        return 0;
78
79    lo = first;
80    hi = r + 1;
81
82    while (lo < hi) {
83        int mid = lo + (hi - lo) / 2;
84
85        if (a[mid] >= v)
86            lo = mid + 1;
87        else
88            hi = mid;
89    }
90
91    return lo - first;
92}
93
94int maxValidSplits(int* nums, int numsSize) {
95
96    int n = numsSize;
97
98    if (n < 2)
99        return 0;
100
101    int *pref = malloc(n * sizeof(int));
102    int *suf = malloc(n * sizeof(int));
103    int *lg = malloc((n + 1) * sizeof(int));
104
105    pref[0] = nums[0];
106
107    for (int i = 1; i < n; i++)
108        pref[i] = gcd(pref[i - 1], nums[i]);
109
110    suf[n - 1] = nums[n - 1];
111
112    for (int i = n - 2; i >= 0; i--)
113        suf[i] = gcd(suf[i + 1], nums[i]);
114
115    lg[1] = 0;
116
117    for (int i = 2; i <= n; i++)
118        lg[i] = lg[i / 2] + 1;
119
120    int K = lg[n] + 1;
121
122    int **st = malloc(K * sizeof(int *));
123
124    for (int k = 0; k < K; k++) {
125        int len = n - (1 << k) + 1;
126        st[k] = malloc(len * sizeof(int));
127    }
128
129    for (int i = 0; i < n; i++)
130        st[0][i] = nums[i];
131
132    for (int k = 1; k < K; k++) {
133
134        int half = 1 << (k - 1);
135        int len = n - (1 << k) + 1;
136
137        for (int i = 0; i < len; i++) {
138            st[k][i] = gcd(
139                st[k - 1][i],
140                st[k - 1][i + half]
141            );
142        }
143    }
144
145    int best = 0;
146
147    /* No deletion */
148    for (int i = 0; i < n - 1; i++) {
149        if (pref[i] == suf[i + 1])
150            best++;
151    }
152
153    /* Delete nums[d] */
154    for (int d = 0; d < n; d++) {
155
156        int score = 0;
157
158        /*
159         * Splits before d
160         */
161        int kmax;
162
163        if (d == n - 1)
164            kmax = d - 2;
165        else
166            kmax = d - 1;
167
168        int tail = (d + 1 < n) ? suf[d + 1] : 0;
169
170        int k = kmax;
171
172        while (k >= 0) {
173
174            int g;
175
176            if (k < d - 1)
177                g = rangeGcd(st, lg, k + 1, d - 1);
178            else
179                g = 0;
180
181            /*
182             * Find the whole range where this gcd remains same.
183             */
184            int lo = 0;
185            int hi = k;
186
187            while (lo < hi) {
188
189                int mid = lo + (hi - lo) / 2;
190
191                int x;
192
193                if (mid < d - 1)
194                    x = rangeGcd(st, lg, mid + 1, d - 1);
195                else
196                    x = 0;
197
198                if (x == g)
199                    hi = mid;
200                else
201                    lo = mid + 1;
202            }
203
204            int L = lo;
205
206            int rightGcd = gcd(g, tail);
207
208            score += countDesc(
209                pref,
210                rightGcd,
211                L,
212                k
213            );
214
215            k = L - 1;
216        }
217
218        /*
219         * Splits after d
220         */
221        int head = (d > 0) ? pref[d - 1] : 0;
222
223        k = d + 1;
224
225        while (k <= n - 2) {
226
227            int g = rangeGcd(
228                st,
229                lg,
230                d + 1,
231                k
232            );
233
234            /*
235             * Find the whole range where gcd is same.
236             */
237            int lo = k;
238            int hi = n - 2;
239
240            while (lo < hi) {
241
242                int mid =
243                    lo + (hi - lo + 1) / 2;
244
245                int x = rangeGcd(
246                    st,
247                    lg,
248                    d + 1,
249                    mid
250                );
251
252                if (x == g)
253                    lo = mid;
254                else
255                    hi = mid - 1;
256            }
257
258            int R = lo;
259
260            int leftGcd = gcd(head, g);
261
262            score += countAsc(
263                suf,
264                leftGcd,
265                k + 1,
266                R + 1
267            );
268
269            k = R + 1;
270        }
271
272        if (score > best)
273            best = score;
274    }
275
276    for (int k = 0; k < K; k++)
277        free(st[k]);
278
279    free(st);
280    free(pref);
281    free(suf);
282    free(lg);
283
284    return best;
285}