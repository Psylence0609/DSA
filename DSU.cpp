//https://cp-algorithms.com/data_structures/disjoint_set_union.html
//https://www.hackerearth.com/practice/notes/disjoint-set-union-union-find/
#include <bits/stdc++.h>
using namespace std;

int find_set(int v) //Path Compression Optimization
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

/** Here is the implementation of union by size:
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
**/

/**And here is the implementation of union by rank based on the depth of the trees:
void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}
**/

//Both of the above methods have the same time complexity
//Time Complexity O(Alpha(n)) Alpha(n) is theinverse Ackermann Function which grows very slowly.
//~ O(1)
