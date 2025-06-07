#include <iostream>
#include <stdio.h>
using namespace std;
class Disjointset
{
public:
    vector<int> rank, parent, size;
    Disjointset(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUpar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        parent[node] = findUpar(parent[node]);
    }
    void UnionbyRank(int u, int v)
    {
        int upar = findUpar(u);
        int vpar = findUpar(v);
        if (upar == vpar)
        {
            return;
        }
        if (rank[upar] > rank[vpar])
        {
            parent[vpar] = upar;
        }
        else if (rank[upar] < rank[vpar])
        {
            parent[upar] = vpar;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionbysize(int u, int v)
    {
        int u_par = parent[u];
        int v_par = parent[v];
        if (u_par == v_par)
        {
            return;
        }
        ///////-------------------->------>------>
        if (size[u_par] > size[v_par])
        {
            parent[v_par] = u_par;
            size[u_par] += size[v_par];
        }
        else
        {
            parent[u_par] = v_par;
            size[v_par] += size[u_par];
        }
    }
};

int main()
{

    return 0;
}