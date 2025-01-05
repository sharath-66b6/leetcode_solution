class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> res(n, 0);

        for(auto q:shifts)
        {
            if(q[2] == 1){
                res[q[0]]++;
                if(q[1]+1 < n)
                    res[q[1] + 1]--;
            }
            else
            {
                res[q[0]]--;
                if(q[1]+1 < n)
                    res[q[1] + 1]++;
            }
        }

        string ans(n,' ');
        int num = 0;

        for(int i=0;i<n;i++){
            num = (num + res[i]) % 26;
            if(num < 0)
                num += 26;
            
            ans[i] = 'a' + (s[i] - 'a' + num) % 26;
        }
        return ans;
    }
};