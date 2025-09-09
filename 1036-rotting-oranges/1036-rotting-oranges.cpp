class Solution {
public:
    vector<pair<int,int>> dir = {
        {0,1},{1,0},{0,-1},{-1,0}
    };
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int r = grid.size(), c = grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2) 
                    q.push({i,j});
            }
        }
        int ans = -1;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto [i,j] = q.front();
                q.pop();

                for(auto [x,y]:dir){
                    int dx = i+x;
                    int dy = j+y;
                    if(dx>=0 && dy>=0 && dx<r && dy<c)
                    if(grid[dx][dy] == 1){
                        grid[dx][dy] = 2;
                        q.push({dx,dy});
                    }
                }
            }
            ans++;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1) 
                    return -1;
            }
        }

        return ans==-1 ? 0:ans;
    }
};