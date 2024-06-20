#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        
        vector<int> a, b;
        int x;
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            b.push_back(x);
        }
        vector<int> diff;
        for (int i = 0; i < n; i++)
        {
            diff.push_back(a[i] - b[i]);
        }
        int count = 0;
        int max = diff[0];
        for (int i = 1; i < n; i++)
        {
            if (diff[i] > max)
            {
                max = diff[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (diff[i] == max)
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}