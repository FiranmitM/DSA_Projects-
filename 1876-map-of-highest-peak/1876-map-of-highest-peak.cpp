

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Initialize queue with all water cells and set their height to 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        // BFS
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && height[nx][ny] == -1) {
                    height[nx][ny] = height[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return height;
    }
};
