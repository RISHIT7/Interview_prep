#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int init_color = image[sr][sc];
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        // up, down, left, right
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<vector<bool>> vis(image.size(), vector<bool> (image[0].size(), false));
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            int x = p.first;
            int y = p.second;
            image[y][x] = color;
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int dx_val = dx[i];
                int dy_val = dy[i];
                int new_x = x + dx_val;
                int new_y = y + dy_val;
                pair<int, int> new_p = {new_x, new_y};
                if (new_x >= 0 && new_y >= 0 && new_x < image[0].size() && new_y < image.size() && !vis[new_y][new_x] && image[new_y][new_x] == init_color)
                {
                    vis[new_y][new_x] = true;
                    q.push(new_p);
                }
            }
        }
        return image;
    }
};