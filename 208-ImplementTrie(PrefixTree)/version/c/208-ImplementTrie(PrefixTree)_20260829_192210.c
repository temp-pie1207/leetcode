// Last updated: 29/08/2026, 19:22:10
1#include <stdlib.h>
2#include <stdbool.h>
3
4typedef struct TrieNode {
5    struct TrieNode *children[26];
6    bool isEnd;
7} Trie;
8
9Trie* trieCreate() {
10    Trie *root = calloc(1, sizeof(Trie));
11    return root;
12}
13
14void trieInsert(Trie* obj, char* word) {
15    Trie *curr = obj;
16
17    for (int i = 0; word[i] != '\0'; i++) {
18        int index = word[i] - 'a';
19
20        if (curr->children[index] == NULL) {
21            curr->children[index] = calloc(1, sizeof(Trie));
22        }
23
24        curr = curr->children[index];
25    }
26
27    curr->isEnd = true;
28}
29
30bool trieSearch(Trie* obj, char* word) {
31    Trie *curr = obj;
32
33    for (int i = 0; word[i] != '\0'; i++) {
34        int index = word[i] - 'a';
35
36        if (curr->children[index] == NULL)
37            return false;
38
39        curr = curr->children[index];
40    }
41
42    return curr->isEnd;
43}
44
45bool trieStartsWith(Trie* obj, char* prefix) {
46    Trie *curr = obj;
47
48    for (int i = 0; prefix[i] != '\0'; i++) {
49        int index = prefix[i] - 'a';
50
51        if (curr->children[index] == NULL)
52            return false;
53
54        curr = curr->children[index];
55    }
56
57    return true;
58}
59
60void trieFree(Trie* obj) {
61    if (obj == NULL)
62        return;
63
64    for (int i = 0; i < 26; i++) {
65        trieFree(obj->children[i]);
66    }
67
68    free(obj);
69}