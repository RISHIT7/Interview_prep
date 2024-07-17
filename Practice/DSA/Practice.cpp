#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// bfs
void bfs(vector<vector<int>> graph, vector<bool> &vis, int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;

    while (!q.empty())
    {
        int curr_node = q.front();
        q.pop();
        std::cout << curr_node << " ";
        for (auto child: graph[curr_node])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
            }
        }
    }
}

// 01 bfs
// to every graph edge, we assign the weight 0
// we add a reverse edge to all the edges, and give that a weight of 1
// then we use a dequeue instead of a queue, since we all need to add the reverse edges to the correct of the queue
// so now, we add the correct edge to the front of the queue, and the reverse edge to the back of the queue
// and this solves the problem of the 01 bfs :)

// multisource bfs

// dfs
void dfs(vector<vector<int>> graph, vector<bool> &vis, int node)
{
    vis[node] = true;
    std::cout << node << " ";
    for (auto child: graph[node])
    {
        if (!vis[child])
        {
            dfs(graph, vis, child);
        }
    }
}

// TopoSort

// Kahn's Algo
vector<int> Kahn(int n, vector<vector<int>> graph)
{
    // setting up
    queue<int> q;
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto child: graph[i])
        {
            indegree[child]++;
        }
    }

    // Adding all the nodes with indegrree 0 to the queue
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // conintue untill queue is empty
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it: graph[node])
        {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    return topo;
}

// Tarjan's Algo

// Djikstra's Algo

// Bellman Ford

// Floyd Warshall

// Prim's Algo

// Kruskal's Algo

// DSU

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    vector<vector<int>> graph;
    graph = {
        {1, 4, 7}, // 0
        {2}, // 1
        {3}, // 2
        {}, // 3
        {5}, // 4
        {2, 6, 7}, // 5
        {}, // 6
        {} // 7
    };
    vector<bool> vis(graph.size(), false);
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
            bfs(graph, vis, i);
    }
    std::cout << "\n";

    vis = vector<bool>(graph.size(), false);
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
        {
            dfs(graph, vis, i);
        }
    }
    std::cout << "\n";

    vector<int> topo = Kahn(graph.size(), graph);
    for (auto node: topo)
    {
        std::cout << node << " ";
    }
    std::cout << "\n";
    return 0;
}

// Revision list
// 1) topo sort
// 2) Kahn's Algo
// 3) Tarjan's Algo