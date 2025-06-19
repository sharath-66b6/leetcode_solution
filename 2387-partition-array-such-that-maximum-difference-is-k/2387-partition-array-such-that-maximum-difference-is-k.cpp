class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int c=1,i=0;
        for(int j=0;j<nums.size();j++){
            if(abs(nums[i]-nums[j]) > k){
                c++;
                i=j;
            }
        }
        return c;
    }
};