class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> dist(rows, vector<int>(cols, 0));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        queue<pair<int, int>> q;

        // Push all 0's
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(mat[r][c] == 0) {
                    q.push({r, c});
                    visited[r][c] = true;
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nc >= 0 && nr < rows && nc < cols) {

                    if(!visited[nr][nc]) {
                        q.push({nr, nc});

                        dist[nr][nc] = dist[r][c] + 1;

                        visited[nr][nc] = true;
                    }
                }
            }
        }

        return dist;
    }
};