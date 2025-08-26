class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int mx = 0;
        double mxd = 0;
        for(auto d:dimensions){
            double c = sqrt(d[0]*d[0] + d[1]*d[1]);
            if(c > mxd){
                mxd = c;
                mx = d[0]*d[1];
            }else if(c == mxd){
                mx = max(mx, d[0]*d[1]);
            }
        }
        return mx;
    }
};