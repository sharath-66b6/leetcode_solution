class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;

        int x = 1,y = 1, ans = 0;
        n--;
        while(n--){
            ans = x+y;
            x = y;
            y = ans;
        }
        return ans;
    }
};