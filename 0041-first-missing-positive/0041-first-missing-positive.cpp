class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ranges::sort(nums);
        int ind = find(nums.begin(),nums.end(),1) - nums.begin();
        if(ind == nums.size())
            return 1; 
        else{
            cout<<ind<<" ";
            for(int i=ind;i<nums.size()-1;i++){
                if(nums[i+1] - nums[i] > 1){
                    return nums[i]+1;
                }
            }
        }
        return nums[nums.size()-1]+1;
    }
};