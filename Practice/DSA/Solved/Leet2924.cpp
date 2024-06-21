class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (auto pair: edges)
        {
            indegree[pair[1]]++;
        }
        vector<int> ans;
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                ans.push_back(i);
            }
        }
        if (ans.size() != 1)
        {
            return -1;
        }
        else
        {
            return ans[0];
        }
    }
};
