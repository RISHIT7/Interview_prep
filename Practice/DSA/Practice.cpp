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
        cout << curr_node << " ";
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
// TopoSort
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
        {2},
        {0, 3},
        {1, 3, 5},
        {1, 2, 4},
        {},
        {2, 7},
        {5, 7},
        {5, 9},
        {4},
        {8}
    };
    vector<bool> vis(graph.size(), false);
    for (int i = 0; i < graph.size(); i++)
    {
        bfs(graph, vis, i);
    }
    cout << "\n";

    return 0;
}