class Solution {
public:
    bool isprime(int n){
        for(int i=2;i< sqrt(n)+1; i++){
            if(n%i == 0)
                return false;
        }
        return true;
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        vector<vector<int>> dir={
            {0,1},{0,-1},{1,0},{-1,0},
            {1,1},{1,-1},{-1,-1},{-1,1}
        };
        int n = mat.size();
        int m = mat[0].size();
        map<int, int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(auto& v:dir){
                    int dx=v[0], dy=v[1];
                    int num = 0;
                    for(int x=i,y=j; x>=0 && y>=0 && x<n && y<m;
                            x+=dx, y+=dy){
                        num = num*10 + mat[x][y];
                        if(num>10 && isprime(num))
                            mp[num]++;
                    }
                }
            }
        }

        int mx = -1, mxf = -1;
        for(auto& [num, freq]:mp){
            if(freq > mxf){
                mx = num;
                mxf = freq;
            }
            else if(freq == mxf){
                mx = max(mx, num);
            }
        }
        return mx;
    }
};