class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& nums) {
        vector<int> v(100);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int a = nums[i][0], b = nums[i][1];
            int val = a<b? a*10+b : b*10+a;
            ans += v[val];
            v[val]++;
        }
        return ans;
    }
};