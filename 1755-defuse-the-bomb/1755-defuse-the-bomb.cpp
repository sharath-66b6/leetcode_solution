class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> v(n,0);
        if(k==0)
            return v;
        
        for(int i=0;i<n;i++)
        {
            if(k>0){
                for(int j=1;j<=k;j++)
                {
                    v[i]+=code[(i+j)%n];
                }
            }
            else{
                for(int j=i-abs(k);j<i;j++)
                {
                    v[i]+=code[(j+n)%n];
                }
            }
        }
        return v;
    }
};