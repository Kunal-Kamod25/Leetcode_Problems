class Solution {
public:
    void DFS(vector<vector<char>>& board, int r, int c) {
        int rows = board.size();
        int cols = board[0].size();

        queue<pair<int, int>> q;
        q.push({r, c});
        board[r][c] = '1';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r1, c1] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r1 + dr[k];
                int nc = c1 + dc[k];

                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols) {
                    if (board[nr][nc] == 'O') {
                        q.push({nr, nc});
                        board[nr][nc] = '1';
                    }
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        // Top row
        for (int c = 0; c < cols; c++) {
            if (board[0][c] == 'O')
                DFS(board, 0, c);
        }

        // Left column
        for (int r = 0; r < rows; r++) {
            if (board[r][0] == 'O')
                DFS(board, r, 0);
        }

        // Bottom row
        for (int c = 0; c < cols; c++) {
            if (board[rows - 1][c] == 'O')
                DFS(board, rows - 1, c);
        }

        // Right column
        for (int r = 0; r < rows; r++) {
            if (board[r][cols - 1] == 'O')
                DFS(board, r, cols - 1);
        }

        // Convert surrounded O -> X and safe 1 -> O
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';

                else if (board[r][c] == '1')
                    board[r][c] = 'O';
            }
        }
    }
};