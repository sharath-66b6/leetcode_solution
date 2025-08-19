class Solution {
private:
    long long sum(int n){
        long long fact = 1;
        for(int i=n;i>1;i--)
            fact += i;
        return fact;
    }
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i=0;
        long long ans=0;
        nums.push_back(9);
        for(int j=0;j<nums.size();j++){
            if(nums[i] == 0 && nums[j] != 0){
                ans += sum(j-i);
                i=j;
            }
            else if(nums[i] != 0 && nums[j] == 0){
                i=j;
            }
        }
        return ans;
    }
};