class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans=0;
        vector<vector<int>> nums(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                if(j==0) nums[i][j] = mat[i][j];
                else if(mat[i][j]==1) nums[i][j] = nums[i][j-1]+1;
                else nums[i][j] = 0; 
            
                int mn = nums[i][j];
                for(int k=i;k>=0;k--){
                    mn = min(mn, nums[k][j]);
                    ans += mn;
                }
                
            }
            
        }
        return ans;
    }
};