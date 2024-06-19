#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<int> graph[], stack<int> &st, int visited[])
{
    visited[node] = 1;
    for (auto it : graph[node])
    {
        if (!visited[it])
            topoSort(it, graph, st, visited);
    }
    st.push(node);
}

int main()
{
    vector<int> graph[6];
    graph[1].push_back(2);
    graph[3].push_back(1);
    graph[4].push_back(5);

    stack<int> st;
    int visited[6] = {0};
    for (int i = 1; i < 6; i++)
    {
        if (!visited[i])
        {
            topoSort(i, graph, st, visited);
        }
    }
    cout << "Topological Sort: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}