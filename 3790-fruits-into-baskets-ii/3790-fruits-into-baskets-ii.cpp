class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int rem=fruits.size();
        for(int f:fruits){
            for(int i=0;i<baskets.size();i++){
                if(f <= baskets[i]){
                    baskets[i] = -1;
                    rem--;
                    break;
                }
            }
        }
        return rem;
    }
};