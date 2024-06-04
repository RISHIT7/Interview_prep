#include <bits/stdc++.h>
using namespace std;

int n, W, K;
int w[1001], p[1001];

// dp
int dp[101][1001][1001];

int rec(int i, int w_taken, int k_taken){
    // pruning
    // base case
    if (i==n) {
        return 0;
    }

    // cache check
    if (dp[i][w_taken][k_taken] != -1) {
        return dp[i][w_taken][k_taken];
    }

    // recursion
    int best = rec(i+1, w_taken, k_taken);
    if (w_taken + w[i] <= W && k_taken + 1 <= K){
        cout << "i: " << i << " w_taken: " << w_taken << " k_taken: " << k_taken << " p[i]: " << p[i] << endl;
        best = max(best, rec(i+1, w_taken + w[i], k_taken + 1) + p[i]);
    }
    // return
    dp[i][w_taken][k_taken] = best;
    return dp[i][w_taken][k_taken];
}

int main()
{
    cin >> n >> W >> K;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> p[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = rec(0, 0, 0);
    cout << ans << endl;
    return 0;
}