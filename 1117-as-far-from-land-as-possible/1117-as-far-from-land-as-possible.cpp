class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        // Initialize the queue with all land cells
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        // If all cells are land or all are water
        if (q.empty() || q.size() == n * n) return -1;

        // 4 possible directions
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int maxDist = -1;

        // BFS
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front(); q.pop();

                for (auto [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = grid[x][y] + 1; // Use land values as distance marker
                        maxDist = max(maxDist, grid[nx][ny] - 1);
                        q.push({nx, ny});
                    }
                }
            }
        }

        return maxDist;
    }
};
