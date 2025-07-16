class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0, odd=0, both=0;
        int c = -1;
        for(int n:nums){
            if(n%2 == 0) even++;
            else odd++;
            if(n%2 != c) both++; c=n%2;
        }
        return max({even, odd, both});
    }
};