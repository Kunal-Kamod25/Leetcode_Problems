class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        vector<vector<bool>> V(rows, vector<bool>(cols, false));

        // Push all land cells
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {

                if(grid[r][c] == 1) {
                    q.push({r, c});
                    V[r][c] = true;
                }
            }
        }

        // Edge cases
        if(q.empty() || q.size() == rows * cols)
            return -1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int distance = -1;

        while(!q.empty()) {

            int sz = q.size();

            while(sz > 0) {

                auto [r, c] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nc >= 0 &&
                       nr < rows && nc < cols) {

                        if(grid[nr][nc] == 1)
                            continue;

                        if(V[nr][nc])
                            continue;

                        q.push({nr, nc});
                        V[nr][nc] = true;
                    }
                }

                sz--;
            }

            distance++;
        }

        return distance;
    }
};