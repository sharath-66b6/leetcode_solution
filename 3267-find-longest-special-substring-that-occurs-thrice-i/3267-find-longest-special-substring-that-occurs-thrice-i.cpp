class Solution {
public:
    int maximumLength(string s) {
        map<string,int> m;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=0;j<=s.size()-i;j++)
            {
                string sub=s.substr(j,i);
                if (all_of(sub.begin(), sub.end(), [&](char c) { return c == sub[0]; })) {
                    m[sub]++;
                }
            }
        }
        int mlen =-1;
        for (auto &[sub, count] : m) {
            if (count >= 3) {
                mlen = max(mlen, (int)sub.length());
            }
        }
        return mlen;
    }
};