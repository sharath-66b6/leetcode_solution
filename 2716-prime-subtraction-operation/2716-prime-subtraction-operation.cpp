class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        if(nums[n-1] < n) return false;

        vector<int> primes(1000 + 1, 1);
        primes[1] = 0;
        for (int i = 2; i <= sqrt(1000 + 1); i++) {
            if (primes[i] == 1) {
                for (int j = i * i; j <= 1000; j += i) {
                    primes[j] = 0;
                }
            }
        }

        int val=1,i=0;
        while(i<n)
        {
            int diff = nums[i] - val;
            if(diff<0) return false;

            if(primes[diff] == 1 || diff == 0)
            {
                i++;
                val++;
            }
            else{
                val++;
            }
        }
        return true;
    }
};