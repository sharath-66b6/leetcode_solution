class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;
        int mx=0;
        for(int n:nums){
            mp[n]++;
            mx = max(mx, mp[n]);
        }
        int ans=0;
        for(auto [num,f]:mp){
            if(f == mx) ans += f;
        }
        return ans;

    }
};