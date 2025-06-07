class Solution {
public:
    string clearStars(string s) {
        string ans = s;
        vector<vector<int>> v(26);

        for (int i = 0; i < s.length(); ++i)
            if (s[i] == '*') {
                ans[i] = ' ';
                int j = 0;
                while (v[j].empty())
                    ++j;
                ans[v[j].back()] = ' ', v[j].pop_back();
            } else {
                v[s[i] - 'a'].push_back(i);
        }

        erase(ans, ' ');
        return ans;
    }
};
