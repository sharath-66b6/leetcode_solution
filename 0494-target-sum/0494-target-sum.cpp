class Solution {
public:
    vector<int> v;
    int t,c=0;
    void solve(int curr,int i)
    {
        // if(curr > t)
        //     return;
        if(i == v.size()){
            if(curr == t)
                c++;
            return;
        }
        solve(curr+v[i], i+1);
        solve(curr-v[i], i+1);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        v = nums;
        t = target;
        solve(0,0);
        return c;
    }
};