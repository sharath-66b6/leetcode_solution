class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int i=0;
        while(i < nums.size()-1){
            int val = gcd(nums[i],nums[i+1]);
            if(val > 1){
                nums[i] = lcm(nums[i], nums[i+1]);
                nums.erase(nums.begin()+i+1);
                if(i>0) i--;
            }
            else{
                i++;
            }
        }
        return nums;
    }
};