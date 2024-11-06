class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());
        while(nums != sorted){
            for(int i=0;i<n-1;i++)
            {
                if(nums[i] > nums[i+1])
                {
                    if(__builtin_popcount(nums[i]) == __builtin_popcount(nums[i+1]))
                        swap(nums[i],nums[i+1]);
                    else
                        return false;
                }
            }
        }
        return true;
    }
};