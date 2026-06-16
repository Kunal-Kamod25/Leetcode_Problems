class Solution {
public:

    void markAllConnected(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r1, c1] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r1 + dr[k];
                int nc = c1 + dc[k];

                if (nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols &&
                    grid[nr][nc] == '1') {

                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int islands = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (grid[r][c] == '1') {
                    islands++;
                    markAllConnected(grid, r, c);
                }

            }
        }

        return islands;
    }
};