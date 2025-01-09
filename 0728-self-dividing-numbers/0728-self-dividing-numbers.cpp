class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int num=left; num<=right; num++)
        {
            string s = to_string(num);
            if(s.find('0') == string::npos){
                bool valid = true;
                for(char i:s)
                {
                    if(num%(i-'0') != 0)
                    {
                        valid = false;
                        break;
                    }
                }
                if(valid)
                    ans.push_back(num);
            }
        }
        return ans;
    }
};