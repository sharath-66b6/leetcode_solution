class Solution {
public:
    int fn(vector<int>& nums, int x){
        int pairs = 0;
        for (int i = 1; i < nums.size(); ++i)
        if (nums[i] - nums[i - 1] <= x) {
            ++pairs;
            ++i;
        }
        return pairs;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = nums.back() - nums.front();

        while (l < r) {
        const int m = (l + r) / 2;
        if (fn(nums, m) >= p)
            r = m;
        else
            l = m + 1;
        }

        return l;
    }
};