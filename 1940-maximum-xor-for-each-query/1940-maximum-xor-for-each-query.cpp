class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> result;
        int x=pow(2,maximumBit) - 1;
        int val = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            result.push_back(val ^ x);
            val = nums[i] ^ val;
        }
        result.push_back(val ^ x);
        reverse(result.begin(),result.end());
        return result;
    }
};