class Solution {
private:
    set<vector<int>> ans;
    void find(int i,vector<int>& vec, vector<int>& nums){
        if(i == nums.size()){
            ans.insert(vec);
            return;
        }

        find(i+1, vec, nums);
        vec.push_back(nums[i]);
        find(i+1, vec, nums);
        vec.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        find(0,vec, nums);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};