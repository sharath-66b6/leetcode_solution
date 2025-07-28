class Solution {
public:
    map<int , int> mp;
    void find(int ind, vector<int>& a, int n, int bval){
        if(ind == n){
            mp[bval]++;
            return;
        }
        find(ind+1, a, n, bval);
        find(ind+1, a, n, bval|a[ind]);
        return;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        find(0, nums, n, 0);
        int ans=0,mx=-1;
        for(auto& [i,v]:mp){
            if(mx<i){
                mx = i;
                ans = v;
            }
        }
        return ans;
    }
};