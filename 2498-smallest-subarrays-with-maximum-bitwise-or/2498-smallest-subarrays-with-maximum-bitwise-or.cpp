class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        vector<int> closest(30);

        for (int i = nums.size() - 1; i >= 0; --i)
        for (int j = 0; j < 30; ++j) {
            if (nums[i] >> j & 1)
            closest[j] = i;
            ans[i] = max(ans[i], closest[j] - i + 1);
        }

        return ans;
    }
};