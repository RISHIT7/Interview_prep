#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> graph[], int n)
{
    vector<bool> visited(n+1, false);
    stack<int> st;
    st.push(node);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            visited[u] = true;
            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                if (!visited[v]) {
                    st.push(v);
                }
            }
        }
    }
    bool res = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << node << " " << i << endl;
            res = false;
            break;
        }
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n+1];
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    bool res = true;
    for (int i = 1; i <= n; i++) {
        if(!dfs(i, graph, n))
        {
            res = false;
            break;
        }
    }
    if (res)
    {
        cout << "YES" <<endl;
    }
    else
    {
        cout << "NO"<<endl;
    }
    return 0;
}