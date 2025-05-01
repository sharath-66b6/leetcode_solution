class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0, l = 0, n=s.size();

        for (int i = 0; i + 1 < n; ++i) {
            if (s[i] == '(' &&  s[i + 1] == ')')
                score += 1 << l;
            l += (s[i] == '(') ? 1 : -1;
        }

        return score;
    }
};