class Solution {
public:
    int minimumLength(string s) {
        map<char,int> m;
        int mn = s.size();
        for(auto c:s)
            m[c]++;
        
        for(auto p:m)
        {
            if(p.second >= 3)
            {
                while(m[p.first] > 2)
                {
                    m[p.first] -= 2;
                    mn -= 2;
                }
            }
        }
        
        return mn;
    }
};