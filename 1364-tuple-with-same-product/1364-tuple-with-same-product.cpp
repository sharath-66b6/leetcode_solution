class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++)
                mp[nums[i]*nums[j]]++;

        }

        int ans = 0;
        for(auto [num,freq]:mp){
            int pair = (freq - 1) * freq / 2;
            ans += 8*pair;
        }

        return ans;
    }
};