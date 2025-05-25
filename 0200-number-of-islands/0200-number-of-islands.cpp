class Solution {
public:
    vector<vector<int>> dir= {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };
    bool isvalid(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m){
        vis[i][j] = 1;

        for(auto d:dir){
            int r = i+d[0];
            int c = j+d[1];

            if(isvalid(r,c,n,m) && !vis[r][c] && grid[r][c] == '1'){
                dfs(r,c,grid,vis,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(),c=0;
        vector<vector<int>> vis(n, vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i, j, grid, vis, n, m);
                    c++;
                }
            }
        }
        return c;
    }
};