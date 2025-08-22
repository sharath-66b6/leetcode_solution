class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int a = 1e9, b = -1e9;
        int x = 1e9, y = -1e9;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    a = min(i, a);
                    b = max(i, b);
                    x = min(j, x);
                    y = max(j, y);
                }
            }
        }
        return (b-a+1)*(y-x+1);
    }
};