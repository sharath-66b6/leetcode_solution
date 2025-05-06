class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(), env.end(), [](auto& a, auto& b){
            if (a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int> lis;
        for (int i=0;i<env.size();++i){
            int h=env[i][1];
            int l=0,r=lis.size();
            while (l<r){
                int m=(l+r)/2;
                if (lis[m]>=h) r=m;
                else l=m+1;
            }
            if (l==lis.size()) lis.push_back(h);
            else lis[l]=h;
        }
        return lis.size();
    }
};
