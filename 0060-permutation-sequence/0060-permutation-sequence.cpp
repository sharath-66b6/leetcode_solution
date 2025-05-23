class Solution {
public:
    vector<string> v;

    int fact(int n){
        if(n <= 1) return 1;
        return n * fact(n - 1);
    }

    string solve(int n, int k){
        if(n == 1){
            return v[0];
        }

        int n_fact = fact(n - 1);
        int index = k / n_fact;
        string num = v[index];
        v.erase(v.begin() + index);
        k = k % n_fact;

        return num + solve(n - 1, k);
    }

    string getPermutation(int n, int k) {
        v.clear();
        for(int i = 1; i <= n; i++){
            v.push_back(to_string(i));
        }
        return solve(n, k - 1);
    }
};
