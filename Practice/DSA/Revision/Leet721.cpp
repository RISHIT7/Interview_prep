#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) {
        int par_x = find(x);
        int par_y = find(y);

        if (par_x != par_y)
            parent[par_x] = par_y;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        unordered_map<string, int> mailNameMap;
        //make initial mapping of mails with name, 
        //while making mapping if mail is already seen,
        //map the mail with super parent
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mailNameMap.find(mail) == mailNameMap.end()) {
                    mailNameMap[mail] = i;
                } else {
                    Union(i, mailNameMap[mail]);
                }
            }
        }
        unordered_map<int, vector<string>> finalMap;
        for (auto& pair : mailNameMap) {
            string mail = pair.first;
            int person = find(pair.second);//map mail with super parents
            finalMap[person].push_back(mail);
        }

        //sort the mails, add the User Name in the front and store in result
        vector<vector<string>> result;
        for (auto& pair : finalMap) {
            int person = pair.first;
            auto list = pair.second;
            sort(begin(list), end(list));
            vector<string> temp;
            temp.push_back(accounts[person][0]);
            for (auto& name : list) {
                temp.push_back(name);
            }
            result.push_back(temp);
        }

        return result;
    }
};