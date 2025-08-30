class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int>& nums, int t, vector<int>& v){
        if(t == 0){
            ans.push_back(v);
            return;
        }
        if(i == nums.size()){
            return;
        }
        if(nums[i] <= t){
            v.push_back(nums[i]);
            solve(i, nums, t-nums[i], v);
            v.pop_back();
        }
        solve(i+1, nums, t, v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        solve(0, candidates, target, v);
        return ans;

    }
};