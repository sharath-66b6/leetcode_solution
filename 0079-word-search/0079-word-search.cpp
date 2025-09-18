class Solution {
private:
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

    bool dfs(int i, int j, int ind, const string &word, vector<vector<char>>& board) {
        if (ind == word.size()) return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[ind]) 
            return false;

        char t = board[i][j];
        board[i][j] = '#'; // mark visited

        for (auto &d : dir) {
            int x = i + d[0], y = j + d[1];
            if (dfs(x, y, ind + 1, word, board)) {
                board[i][j] = t;
                return true;
            }
        }

        board[i][j] = t; // restore
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        // Early pruning: check if board has enough characters
        unordered_map<char,int> freqBoard, freqWord;
        for (auto &row : board)
            for (auto &c : row) freqBoard[c]++;
        for (auto &c : word) freqWord[c]++;
        for (auto &p : freqWord)
            if (freqBoard[p.first] < p.second) return false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && dfs(i, j, 0, word, board))
                    return true;
            }
        }
        return false;
    }
};
