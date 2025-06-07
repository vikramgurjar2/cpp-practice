#include <iostream>
#include <unordered_map>
#include <list>
#include <bits/stdc++.h>
using namespace std;

class graph
{

public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addedges(int u, int v, int distance)
    {
        pair<int, int> p = make_pair(v, distance);
        adj[u].push_back(p);
    }
    void print_graph()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "{" << j.first << "," << j.second << "}"
                                                             ",";
            }
            cout << endl;
        }
    }
    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo)
    {
        visited[node] = true;

        for (auto i : adj[node])
        {
            if (!visited[i.first])
            {
                dfs(i.first, visited, topo);
            }
        }
        topo.push(node);
    }
    void dist_sort(int src, vector<int> &dist, stack<int> &st)
    {
        dist[src] = 0;
        while (!st.empty())
        {
            int front = st.top();
            st.pop();
            if (dist[front] != INT_MAX)
            {
                for (auto k : adj[front])
                {
                    if (dist[k.first] > dist[front] + k.second)
                    {
                        dist[k.first] = dist[front] + k.second;
                    }
                }
            }
        }
    }
};

using namespace std;
int main()
{
    int n;
    cout << "enter the number of nodes" << endl;
    cin >> n;
    int m;
    cout << "enter the number of edges" << endl;
    cin >> m;

    graph g;

    g.addedges(0, 1, 5);
    g.addedges(0, 2, 3);
    g.addedges(1, 2, 2);
    g.addedges(1, 3, 6);
    g.addedges(2, 3, 7);
    g.addedges(2, 4, 4);
    g.addedges(2, 5, 2);
    g.addedges(3, 4, -1);
    g.addedges(4, 5, -2);

    cout << "printing the graph" << endl;
    g.print_graph();
    stack<int> topo;
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {

            g.dfs(i, visited, topo);
        }
    }
    cout << "the top of stack" << topo.top() << endl;

    vector<int> dist(n, INT_MAX);
    g.dist_sort(1, dist, topo);
    cout << dist[2] << endl;

    return 0;
}