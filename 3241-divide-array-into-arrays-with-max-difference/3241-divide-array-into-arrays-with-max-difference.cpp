class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i+=3){
            vector<int> v;
            if(nums[i+2]-nums[i] > k) return vector<vector<int>>{};
            v.push_back(nums[i]);
            v.push_back(nums[i+1]);
            v.push_back(nums[i+2]);
            ans.push_back(v);
        }
        return ans;
    }
};