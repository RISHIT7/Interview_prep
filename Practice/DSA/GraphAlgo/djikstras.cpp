#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define INF INT_MAX

int n, m;
vector<vector<pii>> adj;

void dijkstras(int source)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(n, INF);
    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto &v : adj[u])
        {
            int w = v.first, to = v.second;
            if (dist[to] > dist[u] + w)
            {
                dist[to] = dist[u] + w;
                pq.push({dist[to], to});
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << dist[i] << " ";
    cout << endl;
}