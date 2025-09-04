#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind
{
private:
    vector<int> parent;
    vector<int> size;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;

        if (size[rootX] < size[rootY])
        {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
        else
        {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    int getSize(int x)
    {
        return size[find(x)];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    UnionFind uf(n * n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                if (i - 1 >= 0 && grid[i - 1][j] == 1)
                {
                    uf.unite(n * i + j, n * (i - 1) + j);
                }
                if (i + 1 < n && grid[i + 1][j] == 1)
                {
                    uf.unite(n * i + j, n * (i + 1) + j);
                }
                if (j - 1 >= 0 && grid[i][j - 1] == 1)
                {
                    uf.unite(n * i + j, n * i + j - 1);
                }
                if (j + 1 < n && grid[i][j + 1] == 1)
                {
                    uf.unite(n * i + j, n * i + j + 1);
                }
            }
        }
    }
    int max_size = 0;
    for (int i = 0; i < n * n; i++)
    {
        max_size = max(uf.getSize(i), max_size);
    }
    cout << max_size << endl;
}