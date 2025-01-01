class Solution {
public:
    int maxScore(string s) {
        int count1 = 0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i] == '1')
                count1++;
        }

        int count0 = (s[0] == '0')? 1:0, ans = INT_MIN;
        for(int i=1;i<s.size()-1;i++)
        {
            ans = max(ans, count0 + count1);
            if(s[i] == '1')
                count1--;
            else
                count0++;
            
        }
        ans = max(ans, count0 + count1);
        return ans;
    }
};