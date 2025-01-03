class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = accumulate(nums.begin(),nums.end(),0LL), psum = 0;
        long long count = 0;
        for(long long i=0;i<nums.size()-1;i++)
        {
            psum += nums[i];
            sum  -= nums[i];
            if(psum >= sum)
                count++;
        }
        return count;
    }
};