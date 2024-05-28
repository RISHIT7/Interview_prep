#include <bits/stdc++.h>
using namespace std;

void right(int &i, int &j)
{
    j++;
}
void down(int &i, int &j)
{
    i++;
}
void left(int &i, int &j)
{
    j--;
}
void up(int &i, int &j)
{
    i--;
}

void solve(int n0, int m)
{
    int n = 1;
    int ans = 1;
    int i = 1, j = 1;
    while (i != n0 or j != m)
    {
        right(i, j);
        ans++;
        if (i == n0 and j == m)
            break;
        for (int k = 0; k < n; k++)
        {
            down(i, j);
            ans++;
            if (i == n0 and j == m)
            {
                cout << ans << endl;
                return;
            }
        }
        for (int k = 0; k < n; k++)
        {
            left(i, j);
            ans++;
            if (i == n0 and j == m)
            {
                cout << ans << endl;
                return;
            }
        }

        down(i, j);
        ans++;
        if (i == n0 and j == m)
            break;
        for (int k = 0; k < n + 1; k++)
        {
            right(i, j);
            ans++;
            if (i == n0 and j == m)
            {
                cout << ans << endl;
                return;
            }
        }
        for (int k = 0; k < n + 1; k++)
        {
            up(i, j);
            ans++;
            if (i == n0 and j == m)
            {
                cout << ans << endl;
                return;
            }
        }
        n += 2;
    }
    cout << ans << endl;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        solve(x, y);
    }
}