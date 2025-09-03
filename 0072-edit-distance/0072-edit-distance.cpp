class Solution {
private:
    vector<vector<int>> dp;
    int solve(int i,int j, string a, string b){
        if(j == b.size()){
            return (a.size()-i-1);
        }
        if(i == a.size()) return (b.size()-j-1);

        if(dp[i][j] != -1) return dp[i][j];
        
        if(a[i] == b[j]) return dp[i][j] = 0 + solve(i+1,j+1,a,b);

        //insert
        int in = solve(i,j+1, a, b);

        //delete
        int del = solve(i+1,j,a,b);

        //replace
        int rep = solve(i+1,j+1, a, b);

        return dp[i][j] = 1 + min({in, del, rep}); 

    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        dp.assign(n, vector<int> (m,-1));
        return 1 + solve(0,0, word1, word2);
    }
};