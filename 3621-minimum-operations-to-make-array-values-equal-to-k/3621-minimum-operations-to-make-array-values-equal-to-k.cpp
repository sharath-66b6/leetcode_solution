class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums[0] < k){
            return -1;
        }
        int count=0;
        if(nums[0] != k)
            count++;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] != nums[i])
                count++;
        }
        
        return count;
    }
};