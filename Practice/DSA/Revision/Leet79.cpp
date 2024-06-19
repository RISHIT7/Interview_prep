class Solution {
public:
    int n, m;
    vector<vector<char>> arr;
    string s;

    bool f(int i, int j, int k, vector<vector<bool>> &vis) {
        if(k == s.length()) return true;

        if(i < 0 || i >= m || j < 0 || j >= n || arr[i][j] != s[k] || vis[i][j]) return false;

        vis[i][j] = 1;

        if(f(i + 1, j, k + 1, vis) || f(i - 1, j, k + 1, vis) || f(i, j + 1, k + 1, vis) || f(i, j - 1, k + 1, vis)) return true;

        vis[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        arr = board;
        s = word;
        m = arr.size();
        n = arr[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(f(i, j, 0, vis)) return true;
            }
        }
        return false;
    }
};
