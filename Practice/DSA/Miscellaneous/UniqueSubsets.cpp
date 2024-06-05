#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    set<char> unique_char;
    vector<vector<char>> res;
    vector<char> temp;
    for (int i = 0; i < s.size(); i++)
    {
        if (unique_char.find(s[i]) == unique_char.end()) // O(1) set find operation
        {
            unique_char.insert(s[i]); // O(1) set insert operation
            temp.push_back(s[i]); // O(1) vector push_back operation
        }
        else
        {
            res.push_back(temp); // O(1) vector push_back operation
            temp.clear(); // O(size(temp)) vector clear operation
            temp.push_back(s[i]); // O(1) vector push_back operation
            unique_char.clear(); // O(size(unique_char)) set clear operation
            unique_char.insert(s[i]); // O(1) set insert operation
            // since we clear set every time we dont find a unique_char, the delete operations can be considered amortised O(1)
        }
    }
    if (temp.size() > 0)
    {
        res.push_back(temp);
    }

    for (auto v : res)
    {
        for (auto c : v)
        {
            cout << c << "";
        }
        cout << endl;
    }

    return 0;
}