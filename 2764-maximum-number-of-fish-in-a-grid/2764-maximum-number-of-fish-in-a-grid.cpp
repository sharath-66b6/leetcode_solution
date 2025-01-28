class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i,int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return 0;
        if(grid[i][j] == 0)
            return 0;
        
        int fish = grid[i][j];
        grid[i][j] = 0;
        return fish + dfs(grid,i+1,j) + dfs(grid,i,j+1) + dfs(grid,i-1,j) + dfs(grid,i,j-1);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]>0){
                    ans = max(ans, dfs(grid,i,j));
                }
            }
        }

        
        return ans;
    }
};