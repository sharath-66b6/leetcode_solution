class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans=0;
        auto a = mp.begin(), b = mp.begin();
        if(b != mp.end()) ++b;
        for(; b != mp.end(); ++a, ++b){
            if(abs(a->first - b->first) == 1){
                ans = max(ans,a->second + b->second);
            }
        }
        return ans;
    }
};