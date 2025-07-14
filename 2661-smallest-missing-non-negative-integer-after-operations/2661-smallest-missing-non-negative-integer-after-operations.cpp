class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> v(1e5,0);
        for(int n:nums){
            v[((n%value)+value)%value]++;
        }
        for(int i=0;i<1e5;i++){
            if(--v[i%value] < 0){
                return i;
            }
        }
        return 1e5;
    }
};