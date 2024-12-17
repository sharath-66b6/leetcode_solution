class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<char> pq;
        for(char c:s)
            pq.push(c);
        
        string str = "", d = "";
        int count=0;
        while(!pq.empty())
        {
            char c=pq.top();
            pq.pop();
            if(!str.empty() &&str[str.size()-1] == c)
            {
                if(count == repeatLimit)
                    d+=c;
                else
                {
                    count++;
                    str+=c;
                }
            }
            else
            {
                str+=c;
                if(d.size()>repeatLimit){
                    str+= d.substr(0,repeatLimit);
                    d.erase(0,repeatLimit);
                    count = repeatLimit;
                }
                else if(!d.empty())
                {
                    str+=d;
                    count = d.size();
                    d="";
                }
                else
                    count=1;
            }
        }
        if(count != repeatLimit){
            count = (repeatLimit - count); 
            if(d.size()>count)
                str+= d.substr(0,count);
            else if(!d.empty())
                str+=d;
        }
        return str;
    }
};