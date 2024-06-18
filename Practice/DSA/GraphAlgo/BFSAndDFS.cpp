#include <bits/stdc++.h>
using namespace std;

// recursive
int dfs(int u, vector<int> adj[], vector<bool> &vis)
{
    vis[u] = true;
    for (int v : adj[u])
    {
        if (!vis[v])
            dfs(v, adj, vis);
    }

    return u;
}

// iterative
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

    return 0;
}