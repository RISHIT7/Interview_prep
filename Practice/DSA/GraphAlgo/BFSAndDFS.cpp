#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    int vis[V];
    for (int i = 0; i < V; i++)
        vis[i] = 0;
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> dfs;
    int vis[V];
    for (int i = 0; i < V; i++)
        vis[i] = 0;
    stack<int> st;
    st.push(0);
    vis[0] = 1;
    
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        dfs.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                st.push(it);
            }
        }
    }

    return dfs;
}

int main()
{
    vector<int> adj[5];

    adj[0].push_back(1); // Edge between vertex 0 and vertex 1
    adj[1].push_back(0); // Edge between vertex 1 and vertex 0 (for undirected graph)

    adj[0].push_back(4); // Edge between vertex 0 and vertex 4
    adj[4].push_back(0); // Edge between vertex 4 and vertex 0

    adj[1].push_back(2); // Edge between vertex 1 and vertex 2
    adj[2].push_back(1); // Edge between vertex 2 and vertex 1

    adj[1].push_back(3); // Edge between vertex 1 and vertex 3
    adj[3].push_back(1); // Edge between vertex 3 and vertex 1

    adj[1].push_back(4); // Edge between vertex 1 and vertex 4
    adj[4].push_back(1); // Edge between vertex 4 and vertex 1

    adj[2].push_back(3); // Edge between vertex 2 and vertex 3
    adj[3].push_back(2); // Edge between vertex 3 and vertex 2

    vector<int> bfs = bfsOfGraph(5, adj);
    for (auto it : bfs)
    {
        cout << it << " ";
    }cout << endl;
    
    vector<int> dfs = dfsOfGraph(5, adj);
    for (auto it : dfs)
    {
        cout << it << " ";
    }cout << endl;

    return 0;
}