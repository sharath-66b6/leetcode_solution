class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(),piles.end());
        int low = 1;
        
        while(low <= high){
            long long mid = (low+high)/2, sum=0;
            for(int i=0;i<piles.size();i++){
                sum += (piles[i]+mid-1)/mid;
            }

            if(sum > h){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};