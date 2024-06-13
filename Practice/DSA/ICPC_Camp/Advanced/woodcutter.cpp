#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> trees(n);
    vector<pair<int, bool>> dp(n, {-1, false});

    for (int i = 0; i < n; i++)
        cin >> trees[i].first >> trees[i].second;
    
    function<int(int)>f = [&](int index) {
        if (index == n) return 0;
        if (index == 0) {
            dp[index].first = f(index + 1) + 1;
            dp[index].second = false;
            return dp[index].first;
        }
        if (index == n-1) {
            dp[index].first = f(index + 1) + 1;
            dp[index].second = true;
            return dp[index].first;
        }
        // if the previous tree had fallen right
        if (dp[index-1].second)
        {
            // left
            if (trees[index].first - trees[index-1].first > trees[index].second + trees[index-1].second)
            {
                dp[index].first = f(index + 1) + 1;
                dp[index].second = false;
                return dp[index].first;
            }
            {
                dp[index].first = f(index + 1) + 1;
                dp[index].second = false;
                return dp[index].first;
            }
            // don't fall
            if (trees[index].first - trees[index-1].first == trees[index].second)
            {
                dp[index].first = f(index + 1);
                dp[index].second = false;
                return dp[index].first;
            }
            // fall right
            if (trees[index].first - trees[index-1].first < trees[index].second)
            {
                dp[index].first = f(index + 1) + 1;
                dp[index].second = true;
                return dp[index].first;
            }
        }
        // else
        else
        {
            // left
            if (trees[index].first - trees[index-1].first > trees[index].second)
            {
                dp[index].first = f(index + 1) + 1;
                dp[index].second = false;
                return dp[index].first;
            }
            // don't fall
            if (trees[index].first - trees[index-1].first == trees[index].second)
            {
                dp[index].first = f(index + 1);
                dp[index].second = false;
                return dp[index].first;
            }
            // fall right
            if (trees[index].first - trees[index-1].first < trees[index].second)
            {
                dp[index].first = f(index + 1) + 1;
                dp[index].second = true;
                return dp[index].first;
            }

        }
    };

    

    return 0;
}