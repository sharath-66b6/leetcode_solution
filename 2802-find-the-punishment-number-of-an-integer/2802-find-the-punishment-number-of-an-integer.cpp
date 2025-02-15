class Solution {
public:
    bool partition(string s, int res){
        if(res == 0 && s == "") return true;

        if(res < 0) return false;

        for(int i=0;i<s.size();i++){
            string l = s.substr(0, i+1);
            string r = s.substr(i+1);
            int lnum = stoi(l);

            if(partition(r, res - lnum)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++){
            int s = i*i;
            if(partition(to_string(s), i))
                ans += s;
        }
        return ans;
    }
};