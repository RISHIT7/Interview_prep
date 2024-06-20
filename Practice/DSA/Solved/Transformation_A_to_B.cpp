#include <bits/stdc++.h>
using namespace std;

bool solve(int a, int b, vector<int> &path)
{
    if (a > b)
    {
        return false;
    }
    if (a == b)
    {
        path.push_back(a);
        return true;
    }
    bool twice = solve(2 * a, b, path);
    bool append = solve(10 * a + 1, b, path);

    if (twice || append)
    {
        path.push_back(a);
        return true;
    }
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    vector<int> path;

    bool solved = solve(a, b, path);
    cout << solved << endl;

    if (solved)
    {
        cout << path.size()<< endl;
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
    }
    return 0;
}
