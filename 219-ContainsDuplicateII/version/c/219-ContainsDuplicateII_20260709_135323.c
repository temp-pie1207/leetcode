// Last updated: 09/07/2026, 13:53:23
1#include <stdbool.h>
2#include <stdlib.h>
3
4#define SIZE 100003
5
6typedef struct Node {
7    int val;
8    int idx;
9    struct Node *next;
10} Node;
11
12Node *table[SIZE];
13
14int hash(int x) {
15    if (x < 0) x = -x;
16    return x % SIZE;
17}
18
19bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
20
21    for (int i = 0; i < SIZE; i++)
22        table[i] = NULL;
23
24    for (int i = 0; i < numsSize; i++) {
25        int h = hash(nums[i]);
26        Node *p = table[h];
27
28        while (p) {
29            if (p->val == nums[i]) {
30                if (i - p->idx <= k)
31                    return true;
32                p->idx = i;
33                break;
34            }
35            p = p->next;
36        }
37
38        if (!p) {
39            Node *temp = (Node *)malloc(sizeof(Node));
40            temp->val = nums[i];
41            temp->idx = i;
42            temp->next = table[h];
43            table[h] = temp;
44        }
45    }
46
47    return false;
48}