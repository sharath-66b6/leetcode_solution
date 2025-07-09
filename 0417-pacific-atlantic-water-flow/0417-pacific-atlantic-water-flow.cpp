class Solution {
public:
    void dfs(int r, int c, int n, int m, vector<vector<bool>>& vis,int prevh, vector<vector<int>>& h){
        if(r<0 || c<0 || r>=n || c>=m || vis[r][c] ||  prevh > h[r][c]) return;

        vis[r][c] = true;
        dfs(r+1, c, n, m, vis, h[r][c], h);
        dfs(r, c+1, n, m, vis, h[r][c], h);
        dfs(r-1, c, n, m, vis, h[r][c], h);
        dfs(r, c-1, n, m, vis, h[r][c], h);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> atl(n, vector<bool> (m,0)), pac(n, vector<bool> (m,0));

        for(int i=0;i<n;i++){
            dfs(i, 0, n, m, pac, heights[i][0], heights);
            dfs(i, m-1, n, m, atl, heights[i][m-1], heights);
        }
        for(int i=0;i<m;i++){
            dfs(0, i, n, m, pac, heights[0][i], heights);
            dfs(n-1, i, n, m, atl, heights[n-1][i], heights);
        }

        vector<vector<int>> ans;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(pac[r][c] && atl[r][c])
                    ans.push_back({r,c});
            }
        }
        return ans;
    }
};