class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MIN;
        map<int, int> mp;

        for (int num : nums)
            ++mp[num];

        for (int num : nums) {
            int x = sum - num;
            if (x % 2 == 0) {
                int y = x / 2;
                if (mp[y] > ((num == y)? 1 : 0))
                ans = max(ans, num);
            }
        }
        return ans;
    }
};