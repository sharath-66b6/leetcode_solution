class Solution {
public:
    bool canChange(string start, string target) {
        queue<pair<char,int>> s,t;
        for(int i=0;i<start.size();i++)
        {
            if(start[i] != '_')
                s.push({start[i],i});
            if(target[i] != '_')
                t.push({target[i],i});
        }

        if(s.size() != t.size()) return false;

        while(!s.empty()){
            auto [a,i]=s.front();
            s.pop();

            auto [b,j]=t.front();
            t.pop();

            if(a != b || (a=='L' && i<j) || (b=='R' && i>j))
                return false;
        }
        return true;
    }
};