class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0, time = 0;

        // count fresh oranges and collect rotten ones
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) fresh++;
                if (grid[r][c] == 2) q.push({r,c});
            }
        }

        // 4 directions
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        // BFS
        while (fresh > 0 && !q.empty()) {
            int length = q.size();
            for (int i = 0; i < length; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto &dir : dirs) {
                    int row = r + dir.first;
                    int col = c + dir.second;

                    if (row >= 0 && row < grid.size() &&
                        col >= 0 && col < grid[0].size() &&
                        grid[row][col] == 1) {
                        grid[row][col] =2;
                        q.push({row, col});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;  // If no fresh oranges left, return time
                                            // Else, return -1 (no rotting)
    }
};