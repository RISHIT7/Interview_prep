#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>
using namespace std;

int N, M;
queue<pii> q;
int paths[1005][1005];
pii from[1005][1005];
int oo = INT_MAX;
pii A;
string ans;
bool possible = false;
vector<pii> movements = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void retrace(pii node)
{
    pii origin = from[node.first][node.second];
    if (origin == pii(0, 0)) return;
    if (origin.first == node.first + 1) ans.push_back('U');
    if (origin.first == node.first - 1) ans.push_back('D');
    if (origin.second == node.second + 1) ans.push_back('L');
    if (origin.second == node.second - 1) ans.push_back('R');
    retrace(origin);
}

void check(pii origin, int x, int y) {
    int pl = paths[origin.first][origin.second];
    if (pl + 1 < paths[x][y]) {
        paths[x][y] = pl + 1;
        from[x][y] = origin;
        q.push(pii(x, y));
    }
}

bool mora = false; // false if bfs for monsters, true if bfs for A
void bfs() {
    while (!q.empty())
    {
        pii loc = q.front();
        q.pop();
        int x = loc.first;
        int y = loc.second;
        for (pii dir : movements)
        {
            int new_x = x + dir.first;
            int new_y = y + dir.second;
            check(loc, new_x, new_y);
        }
        if (mora && (loc.first == 1 || loc.second == 1 || loc.first == N || loc.second == M)) {
            cout << "YES\n";
            cout << paths[loc.first][loc.second] << '\n';
            retrace(loc);
            possible = true;
            return;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++)
        {
            paths[i][j] = oo;
            if (s[j - 1] == '#')
                paths[i][j] = 0;
            if (s[j - 1] == 'M')
            {
                q.push(pii(i, j)); // pushing all the sources for multisource bfs
                paths[i][j] = 0;
            }
            if (s[j - 1] == 'A')
            {
                A.first = i;
                A.second = j;
            }
        }
    }
    bfs(); // monster bfs
    mora = true;
    from[A.first][A.second] = pii(0, 0);
    paths[A.first][A.second] = 0;
    q.push(A);
    bfs(); // A bfs
    if (possible) {
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    else {
        cout << "NO\n";
    }

    return 0;
}