class Solution {
public:
    bool isSubset(const map<char, int>& map1, const map<char, int>& map2) {
        for (const auto& pair : map1) {
            auto it = map2.find(pair.first);
            if (it == map2.end() || it->second < pair.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        if (n < t.size()) return "";

        map<char, int> mt;
        for (char c : t) {
            mt[c]++;
        }

        map<char, int> ms;
        int i = 0, mn = INT_MAX, req = t.size(), start = 0 ;

        for (int j = 0; j < n; j++) {
            char c = s[j];
            if(mt[c] > 0)
            {
                if(ms[c] < mt[c])
                    req--;
                ms[s[j]]++;
            }
            while (req == 0) {
                if (mn > j - i + 1) {
                    mn = j - i + 1;
                    start = i;
                }

                if (mt[s[i]] > 0) {
                    if(mt[s[i]] == ms[s[i]])
                        req++;
                    ms[s[i]]--;
                }
                i++;
            }
        }

        return mn == INT_MAX ? "":s.substr(start,mn);
    }
};
