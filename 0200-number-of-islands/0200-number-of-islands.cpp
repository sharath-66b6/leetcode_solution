class Solution {
public:
    vector<vector<int>> dist = {{0,1},{1,0},{0,-1},{-1,0}};
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vist){
        vist[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(auto d:dist){
                int x = i+d[0];
                int y = j+d[1];
                if(x >= 0 && x < n && y >= 0 && y < m &&
                    grid[x][y] == '1' && !vist[x][y]){
                        vist[x][y] = 1;
                        q.push({x,y});
                    }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vist(n, vector<int> (m,0));
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vist[i][j]){
                    c++;
                    bfs(i, j, grid, vist);
                }
            }
        }
        return c;
    }
};