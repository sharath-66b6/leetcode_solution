class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                string str1 = words[i];
                string str2 = words[j];
                if (str2.substr(0, str1.length()) == str1 && str2.substr(str2.length() - str1.length()) == str1) 
                    ans++;
            }
        }
        return ans;
    }
};