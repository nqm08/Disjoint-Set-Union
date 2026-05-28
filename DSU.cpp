#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, int> parent;
unordered_map<int, int> sz;

int components;

void makeSet(vector<int> nodes)
{
    components = nodes.size();

    for (int x : nodes)
    {
        parent[x] = x;
        sz[x] = 1;
    }
}

int Find(int u)
{
    if (parent[u] == u)
        return u;

    return parent[u] = Find(parent[u]);
}

void Union(int a, int b)
{
    int rootA = Find(a);
    int rootB = Find(b);

    if (rootA != rootB)
    {
        if (sz[rootA] < sz[rootB])
            swap(rootA, rootB);

        parent[rootB] = rootA;
        sz[rootA] += sz[rootB];

        components--;
    }
}

int main()
{
    vector<int> nodes = {10, 20, 35, 100, 200};

    makeSet(nodes);

    Union(10, 20);
    Union(20, 35);
    Union(100, 200);

    for (int x : nodes)
    {
        cout << "Root cua " << x << " la: " << Find(x) << endl;
    }

    cout << "\nSo nhom hien tai: "
         << components << endl;

    return 0;
}