class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0;i<9;i++){
            vector<int> row(10,0);
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                row[board[i][j]-'0']++;
                if(row[board[i][j]-'0'] > 1) return false;
            }
        }

        for(int j=0;j<9;j++){
            vector<int> col(10,0);
            for(int i=0;i<9;i++){
                if(board[i][j] == '.') continue;
                col[board[i][j]-'0']++;
                if(col[board[i][j]-'0'] > 1) return false;
            }
        }

        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                vector<int> sub(10,0);
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        if(board[x][y] == '.') continue;
                        sub[board[x][y]-'0']++; 
                        if(sub[board[x][y]-'0'] > 1) return false;
                    }
                }
            }
        }
        return true;
    }
};