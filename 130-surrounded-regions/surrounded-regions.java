class Solution {

    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};

    public void dfs(char[][] board, int i, int j) {

        int n = board.length;
        int m = board[0].length;

        if (i < 0 || j < 0 || i >= n || j >= m ||
            board[i][j] != 'O') {
            return;
        }

        // This O is connected to the boundary
        board[i][j] = '#';

        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];

            dfs(board, nx, ny);
        }
    }

    public void solve(char[][] board) {

        int n = board.length;
        int m = board[0].length;

        // Top + bottom
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);

            if (board[n - 1][j] == 'O')
                dfs(board, n - 1, j);
        }

        // Left + right
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);

            if (board[i][m - 1] == 'O')
                dfs(board, i, m - 1);
        }

        // Capture surrounded regions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
}