class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long total = 0;
        long long good = 0;
        map<int,int> c;
        for(int i=0;i<nums.size();i++){
            total += i;
            good += c[nums[i] - i];
            c[nums[i] - i]++;
        }

        return total - good;
    }
};