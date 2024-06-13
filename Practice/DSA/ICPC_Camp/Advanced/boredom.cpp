#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
#define int long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> freq(N), dp(N, -1);

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        freq[x]++;
    }

    function<int(int)>f = [&](int index) {
        if (index > N) return 0ll;
        if (dp[index] != -1) return dp[index];
        return dp[index] = max(f(index + 1), (index * freq[index]) + f(index + 2));
    };

    return 0;
}
