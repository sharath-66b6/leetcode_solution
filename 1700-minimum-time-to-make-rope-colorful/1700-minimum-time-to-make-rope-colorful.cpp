class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum=neededTime[0],mx,ans=0, c=1;
        mx = sum;
        for(int i=1;i<colors.size();i++){
            if(colors[i-1] == colors[i]){
                sum += neededTime[i];
                mx = max(mx, neededTime[i]);
                c++;
            }
            else if(c>1){
                ans += sum - mx;
                sum = mx = neededTime[i];
                c=1;
            }
            else{
                sum = mx = neededTime[i];
                c=1;
            }
        }
        ans += sum - mx;
        return ans;
    }
};