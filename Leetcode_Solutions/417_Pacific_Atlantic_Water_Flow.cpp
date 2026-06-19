class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> ans;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {

                queue<pair<int, int>> q;

                vector<vector<bool>> V(
                    rows,
                    vector<bool>(cols, false)
                );

                q.push({r, c});
                V[r][c] = true;

                bool po = false;
                bool ao = false;

                // BFS
                while(!q.empty()) {

                    auto [r1, c1] = q.front();
                    q.pop();

                    // Pacific
                    if(r1 == 0 || c1 == 0)
                        po = true;

                    // Atlantic
                    if(r1 == rows - 1 || c1 == cols - 1)
                        ao = true;

                    for(int k = 0; k < 4; k++) {

                        int nr = r1 + dr[k];
                        int nc = c1 + dc[k];

                        if(nr >= 0 && nc >= 0 &&
                           nr < rows && nc < cols) {

                            if(!V[nr][nc] &&
                               heights[r1][c1] >= heights[nr][nc]) {

                                q.push({nr, nc});
                                V[nr][nc] = true;
                            }
                        }
                    }
                }

                if(po && ao)
                    ans.push_back({r, c});
            }
        }

        return ans;
    }
};