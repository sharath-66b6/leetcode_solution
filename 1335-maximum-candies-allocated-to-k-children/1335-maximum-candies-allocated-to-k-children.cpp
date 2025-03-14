class Solution {
public:
    bool find(vector<int>& candies, long long k, int num){
        long long int mx = 0;

        for(auto x:candies){
            mx += x/num;
        }
        return mx >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        
        int mx = 0;
        for(int x:candies){
            mx = max(mx, x);
        }

        int l=0, r=mx;
        while(l<r){
            int mid = (l + r+1)/2;
            if(find(candies, k, mid)){
                l = mid;
            }
            else{
                r = mid-1;
            }
        }

        return l;
    }
};