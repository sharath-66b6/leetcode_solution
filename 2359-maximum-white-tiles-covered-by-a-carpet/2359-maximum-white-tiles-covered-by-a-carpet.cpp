class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& t, int l) {
        sort(t.begin(),t.end());
        vector<int>s,p(t.size()+1);
        for(int i=0;i<t.size();i++)
            s.push_back(t[i][0]);
        for(int i=0;i<t.size();i++){
            p[i+1]=p[i]+t[i][1]-t[i][0]+1;
        }
        for(int i=0;i<t.size();i++){
            if(t[i][1]-t[i][0]+1>=l)
                return l;
        }
        int a=0;
        for(int i=0;i<t.size();i++){
            int x=t[i][0],e=x+l-1;
            int j=upper_bound(s.begin(),s.end(),e)-s.begin()-1;
            int n=0;
            if(t[j][1]>e)n=t[j][1]-e;
            a=max(a,p[j+1]-p[i]-n);
        }
        return a;
    }
};
