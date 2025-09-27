class Solution {
public:
    int trap(vector<int>& height) {
        int i=0, j=height.size()-1;
        int lmx=0, rmx=0, ans=0;
        while(i<j){
            if(height[i]<=height[j]){
                if(lmx > height[i])
                    ans += lmx - height[i];
                else
                    lmx = height[i];
                i++; 
            }
            else{
                if(rmx > height[j])
                    ans += rmx - height[j];
                else
                    rmx = height[j];
                j--;
            }
        }
        return ans;
    }
};