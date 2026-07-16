class Solution {

    public boolean isValidPos(char[][] board, char ch, int row, int col) {

        // Check column
        for (int i = 0; i < 9; i++) {
            if (i != row && board[i][col] == ch)
                return false;
        }

        // Check row
        for (int i = 0; i < 9; i++) {
            if (i != col && board[row][i] == ch)
                return false;
        }

        // Check 3x3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if ((i != row || j != col) && board[i][j] == ch)
                    return false;
            }
        }

        return true;
    }

    public boolean isValidSudoku(char[][] board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.')
                    continue;

                if (!isValidPos(board, board[i][j], i, j))
                    return false;
            }
        }

        return true;
    }
}