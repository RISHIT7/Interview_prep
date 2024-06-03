#include <bits/stdc++.h>
using namespace std;



int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    n--;

    vector<pair<int, pair<int, int>>> tree;
    while(n--)
    {
        int a, b;
        cin >> a >> b;

        // check if a is already present in the tree
        bool found = false;
        for (auto i = tree.begin(); i != tree.end(); i++)
        {
            if (i->first == a)
            {
                // .second.first is the child of a that already exists
                i->second.second = b;
                found = true;
                break;
            }
        }
        if (!found)
        {
            tree.push_back({a, {b, 0}});
        }

        for (auto i : tree)
        {
            cout << i.first << " " << i.second.first << " " << i.second.second << endl;
        }

        // left traversal
        int left = 0;
        auto i = tree.begin();
        while (i->second.first != 0)
        {
            left++;
            i = find_if(tree.begin(), tree.end(), [i](pair<int, pair<int, int>> p) { return p.first == i->second.first; });
        }

        // right traversal
        int right = 0;
        i = tree.begin();
        while (i->second.second != 0)
        {
            right++;
            i = find_if(tree.begin(), tree.end(), [i](pair<int, pair<int, int>> p) { return p.first == i->second.second; });
        }

        cout << left << " " << right << endl;
    }

    return 0;
}