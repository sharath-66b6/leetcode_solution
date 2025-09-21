class Solution {
private:
    vector<vector<string>> ans;
    
    void solve(int r, int n, vector<int>& col, vector<int>& dia1, vector<int>& dia2, vector<string>& queens){
        if(n==r){
            ans.push_back(queens);
            return;
        }

        for(int c=0;c<n;c++){
            if(col[c] || dia1[r-c+n-1] || dia2[r+c]) continue;

            queens[r][c] = 'Q';
            col[c] = dia1[r-c+n-1] = dia2[r+c] = 1;
            solve(r+1, n, col, dia1, dia2, queens);
            queens[r][c] = '.';
            col[c] = dia1[r-c+n-1] = dia2[r+c] = 0;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> queens(n, string(n, '.'));
        vector<int> col(n,0), dia1(2*n-1,0), dia2(2*n-1,0);
        solve(0,n,col,dia1,dia2,queens);
        return ans;
    }
};