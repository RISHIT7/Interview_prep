#include <iostream>
#include <vector>
using namespace std;

#define pii pair<int, int>

bool detect_cycle(vector<pair<pii, int>> edges, int n)
{
    vector<int> dist(n + 1, 1e9);
    for (int i = 1; i <= n; i++)
    {
        for (auto edge : edges)
        {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    bool res = false;
    int first = -1;
    for (auto edge : edges)
    {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
        if (dist[u] + w < dist[v])
        {
            if (first == -1)
                first = u;
            dist[v] = dist[u] + w;
            cout << u << " ";
            res = true;
            if (v == first)
                break;
        }
    }
    cout << first << endl;
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<pii, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }
    bool res = detect_cycle(edges, n);
    cout << "----------------- RES ------------------\n"
            << res <<  
          "\n----------------- RES ------------------" << endl;

    return 0;
}