class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c1=0, c2=0;
        int e1=INT_MIN, e2=INT_MIN;

        for(int num:nums){
            if(c1==0 && e2!=num){
                c1 = 1;
                e1 = num;
            }
            else if(c2==0 && e1!=num){
                c2 = 1;
                e2 = num;

            }
            else if(e1 == num) c1++;
            else if(e2 == num) c2++;
            else{
                c1--; c2--;
            }
        }

        c1=0; c2=0;
        for(int num:nums){
            if(num == e1) c1++;
            if(num == e2) c2++;
        }
        vector<int> ans;
        if(c1 > n/3) ans.push_back(e1);
        if(c2 > n/3) ans.push_back(e2);

        return ans;
    }
};