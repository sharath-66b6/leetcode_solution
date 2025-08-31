class Solution {
private:
    bool solve(vector<vector<char>>& b, int s) {
        if (s == 81)
            return true;

        int i = s / 9;
        int j = s % 9;
        if(b[i][j] != '.') return solve(b,s+1);
        for (char num = '1'; num <= '9'; num++) {
            if (isValid(b, i, j, num)) {
                b[i][j] = num;
                if (solve(b, s + 1)) {
                    return true;
                }
                b[i][j] = '.';
            }
        }
        return false;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i)
            if (board[i][col] == c || board[row][i] == c ||
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) { solve(board, 0); }
};