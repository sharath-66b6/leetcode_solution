class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int mx=0, sum=0;
        int i=0;
        map<int, int> mp;
        for(int j=0;j<nums.size();j++){
            while(mp.count(nums[j]) && i != mp[nums[j]]+1){
                sum -= nums[i];
                mp.erase(nums[i]);
                i++;
            }
            mp[nums[j]] = j;
            sum += nums[j];
            mx = max(mx, sum);
        }
        return mx;
    }
};