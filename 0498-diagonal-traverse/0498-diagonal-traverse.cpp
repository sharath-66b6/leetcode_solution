class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        bool isup = true;
        int n = mat.size(), m = mat[0].size(),i=1,j=-1;
        while(i<n || j<m){
            if(isup){
                i--;
                j++;
            }
            else{
                i++;
                j--;
            }

            
            if(i>=n){
                i--;
                j+=2;
                isup = true;
            }
            else if(j>=m){
                j--;
                i+=2;
                isup = false;
            }
            else if(j<0){
                j++;
                isup = true;
            }
            else if(i<0){
                i++;
                isup = false;
            }
            if(i>=0 && i<n && j>=0 && j<m)
                ans.push_back(mat[i][j]);
        }
        return ans;
    }
};