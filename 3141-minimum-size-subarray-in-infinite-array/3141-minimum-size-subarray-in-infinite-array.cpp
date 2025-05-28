class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long tsum = accumulate(nums.begin(), nums.end(), 0L);
        int n = nums.size();
        int len = (target / tsum) * n;
        target  = target % tsum;
        if (target == 0)
        return len;

        int res = n;
        long sum = 0;
        unordered_map<long, int> mp{{0, -1}};

        for (int i = 0; i < 2 * n; ++i) {
        sum += nums[i % n];
        if (auto it = mp.find(sum - target);
            it != mp.cend())
            res = min(res, i - it->second);
        mp[sum] = i;
        }

        return res == n ? -1 : res + len;
    }
};