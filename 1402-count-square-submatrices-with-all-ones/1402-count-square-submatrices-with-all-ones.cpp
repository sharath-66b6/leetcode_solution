class Solution {
public:
    int dpsol(int i, int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(i>=grid.size() || j>=grid[0].size()) return 0;
        if(grid[i][j] == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right=dpsol(i,j+1,grid,dp);
        int diagonal=dpsol(i+1,j+1,grid,dp);
        int below=dpsol(i+1,j,grid,dp);

        return dp[i][j] = 1 + min(right,min(diagonal,below));
    }
    int countSquares(vector<vector<int>>& matrix) {
        int result=0;
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<=matrix[0].size();j++)
            {
                result+=dpsol(i,j,matrix,dp);
            }
        }
        return result;
    }
};