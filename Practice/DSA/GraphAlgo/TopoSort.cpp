#include <bits/stdc++.h>    
using namespace std;

void topoSort(int node, vector<int> adj[], stack<int> &st, int vis[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            topoSort(it, adj, st, vis);
    }
    st.push(node);
}

vector<int> Kahn(int n, vector<int> adj[])
{
    // Kahn's Algorithm
    queue<int> q;
    vector<int> indegree(n, 0);
    for (int i = 0; i < 6; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }

    // 1) Insert all nodes with indegree 0
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // 2) Remove nodes from queue and reduce indegree of adjacent nodes
    vector<int> topo;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        
        for (auto it: adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

}

int main()
{
    vector<int> adj[6];
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[4].push_back(1);
    adj[4].push_back(0);
    adj[5].push_back(0);
    adj[5].push_back(2);

    // using dfs to find topological sort
    stack<int> st;
    int vis[6] = {0};
    for (int i = 0; i < 6; i++)
    {
        if (!vis[i])
            topoSort(i, adj, st, vis);
    }

    // Kahn's Algorithm
    vector<int> topo = Kahn(6, adj);

    return 0;
}