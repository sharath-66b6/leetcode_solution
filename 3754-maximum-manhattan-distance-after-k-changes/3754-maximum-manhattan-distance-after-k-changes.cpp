class Solution {
public:
    int maxDistance(string s, int k) {
        return max({solve(s,k,"NW"),solve(s,k,"NE"),
                    solve(s,k,"SW"),solve(s,k,"SE")});
    }
    int solve(string s, int k, string d){
        int ans=0,pos=0,op=0;
        for(auto c:s){
            if(d.find(c) != string::npos)
                pos++;
            else{
                pos--;
                op++;
            }
            ans = max(ans, pos+2*min(k,op));
        }
        return ans;
    }
};