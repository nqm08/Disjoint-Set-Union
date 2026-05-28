#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int u, v, w;
};
class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}
int main() {
    int n = 4;
    vector<Edge> edges = {
        {1,2,1},
        {2,3,2},
        {1,3,4},
        {3,4,3}
    };
    sort(edges.begin(), edges.end(), cmp);
    DSU dsu(n);
    int totalWeight = 0;
    cout << "Cac canh trong MST:\n";
    for (auto e : edges) {
        if (dsu.unite(e.u, e.v)) {
            cout << e.u << " - " << e.v << " : " << e.w << endl;
            totalWeight += e.w;
        }
    }
    cout << "Tong trong so MST: " << totalWeight << endl;
    return 0;
}