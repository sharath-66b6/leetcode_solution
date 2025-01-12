class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> l,ul;
        for(int i=0;i<s.size();i++)
        {
            if(locked[i] == '0')
                ul.push(i);
            else if(s[i] == '(')
                l.push(i);
            else
            {
                if(!l.empty())
                    l.pop();
                else if(!ul.empty())
                    ul.pop();
                else
                    return false;
            }
        }

        while(!l.empty() && !ul.empty() && l.top() < ul.top())
        {
            l.pop();
            ul.pop();
        }
        if(!l.empty() || ul.size()%2 != 0)
            return false;
        return true;
    }
};