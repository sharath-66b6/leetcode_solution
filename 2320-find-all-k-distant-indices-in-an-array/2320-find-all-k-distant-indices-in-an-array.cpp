class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keys;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                keys.push_back(i);
            }
        }
        set<int> v;
        for(auto n:keys){
            
            for(int i = n-k >= 0? n-k:0;i <= n+k && i<nums.size();i++){
                v.insert(i);
            }
        }
        vector<int> ans(v.begin(),v.end());
        return ans;
    }
};