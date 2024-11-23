class Solution {
public:
    int myAtoi(string s) {
        s.erase(0, s.find_first_not_of(' '));

        if (s.empty()) return 0;

        bool isneg = (s[0] == '-');
        if (s[0] == '-' || s[0] == '+') {
            s = s.substr(1);
        }

        string ans = "";
        for (char c : s) {
            if (!isdigit(c)) break;
            ans += c;
        }

        if (ans.empty()) return 0;

        try {
            long long num = stoll(ans);
            if (isneg) num = -num;

            if (num < INT_MIN) return INT_MIN;
            if (num > INT_MAX) return INT_MAX;
            return static_cast<int>(num);
        } catch (...) {

            return isneg ? INT_MIN : INT_MAX;
        }
    }
};