class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int> v;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                v.push_back(grid[i][j]);

        sort(v.begin(), v.end());
        int n = v.size();
        if(n == 1) return 0;

        int com = v[n/2];
        int mn = 0;
        for(int i=0;i<n;i++){
            if(v[i]%x != com%x) return -1;
            mn += abs(com-v[i])/x;
        }
        return mn;
    }
};