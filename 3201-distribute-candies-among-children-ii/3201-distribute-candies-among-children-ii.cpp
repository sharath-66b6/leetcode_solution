class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        for(int i=0;i<= min(n,limit);i++){
            if(n-i > 2*limit) continue;
            int j = max(0, (n-i) - limit);
            int k = min((n-i), limit);
            ans += (k-j+1);
        }
        return ans;
    }
};