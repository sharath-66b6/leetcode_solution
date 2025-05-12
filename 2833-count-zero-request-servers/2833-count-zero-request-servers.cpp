struct X {
    int i, q;
};

class Solution {
    public:
    vector<int> countServers(int n, vector<vector<int>>& l, int x, vector<int>& q) {
        vector<int> a(q.size()), c(n + 1);
        sort(l.begin(), l.end(), [](auto& A, auto& B){return A[1] < B[1];});
        int i = 0, j = 0, s = 0;
        auto iq = get(q);
        for (auto& p : iq) {
        int idx = p.i, val = p.q;
        while (j < l.size() && l[j][1] <= val) {
            int srv = l[j][0];
            if (++c[srv] == 1) s++;
            j++;
        }
        while (i < l.size() && l[i][1] < val - x) {
            int srv = l[i][0];
            if (--c[srv] == 0) s--;
            i++;
        }
        a[idx] = n - s;
        }
        return a;
    }

    private:
    vector<X> get(vector<int>& q) {
        vector<X> r;
        for (int z = 0; z < q.size(); z++) r.push_back({z, q[z]});
        sort(r.begin(), r.end(), [](X& A, X& B){ return A.q < B.q; });
        return r;
    }
};
