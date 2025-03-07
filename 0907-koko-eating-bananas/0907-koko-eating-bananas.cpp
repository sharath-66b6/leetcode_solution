class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1, r = *max_element(piles.begin(), piles.end());
        
        while(l<r){
            int mid = l + (r-l)/2;

            int sum = 0;
            for(auto num:piles){
                sum += (num+mid-1)/mid;
                if(sum > h){
                    break;
                }
            }
            
            if(sum <= h){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};