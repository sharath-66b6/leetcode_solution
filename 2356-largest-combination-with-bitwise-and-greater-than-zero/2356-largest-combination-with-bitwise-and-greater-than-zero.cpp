class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int sum=0;
        for(int i=0;i<24;i++){
            int c=0;
            for(auto num:candidates)
            {
                if((num & (1 << i)) != 0){
                    c++;
                }
            }
            sum=max(sum,c);
        }
        return sum;
    }
};