#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> &graph)
{
    vector<int> vis(graph.size(), -1); // -1 indicates unvisited, 0 indicates visited from
    queue<int> q;
    for (int i = 0; i < graph.size(); i++)
    {
        int curr_node = i;
        if (vis[curr_node] == -1)
        {
            q.push(curr_node);
            vis[curr_node] = 0;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (int child : graph[node])
                {
                    int color = !vis[node];
                    if (vis[child] == -1)
                    {
                        vis[child] = color;
                        q.push(child);
                    }
                    else if (vis[child] != color)
                        return false;
                }
            }
        }
    }
    return true; // If no cycle is found, the graph is bipartite.
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    bool res = isBipartite(graph);
    cout << (res ? "Yes" : "No") << endl;

    return 0;
}