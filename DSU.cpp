#include <iostream>
using namespace std;

const int MAXN = 1000;

int parent[MAXN];
int size[MAXN];

void makeSet(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

int Find(int u)
{
    if (u == parent[u])
        return u;

    return parent[u] = Find(parent[u]);
}

void Union(int a, int b)
{
    int rootA = Find(a);
    int rootB = Find(b);

    if (rootA != rootB)
    {
        if (size[rootA] < size[rootB])
            swap(rootA, rootB);

        parent[rootB] = rootA;
        size[rootA] += size[rootB];
    }
}

int main()
{
    int n = 5;

    makeSet(n);

    Union(1, 2);
    Union(2, 3);
    Union(4, 5);

    for (int i = 1; i <= n; i++)
    {
        cout << "Root của " << i << " la: " << Find(i) << endl;
    }

    return 0;
}