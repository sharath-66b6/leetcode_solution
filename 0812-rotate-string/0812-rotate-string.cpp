class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string s2=s+s;

        return s2.find(goal) != string::npos;
    }
};