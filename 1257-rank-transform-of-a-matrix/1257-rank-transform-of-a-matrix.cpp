class UnionFind {
public:
    unordered_map<int, int> p;
    void u(int a, int b) {
        if (!p.count(a)) p[a] = a;
        if (!p.count(b)) p[b] = b;
        int pa = f(a), pb = f(b);
        if (pa != pb) p[pa] = pb;
    }
    int f(int x) {
        return p[x] == x ? x : p[x] = f(p[x]);
    }
    unordered_map<int, vector<int>> g() {
        unordered_map<int, vector<int>> r;
        for (auto& [x, _] : p) r[f(x)].push_back(x);
        return r;
    }
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                mp[mat[i][j]].push_back({i, j});

        vector<int> rank(m + n);

        for (auto& [v, cells] : mp) {
            UnionFind uf;
            for (auto& [i, j] : cells)
                uf.u(i, j + m);

            auto grp = uf.g();
            unordered_map<int, int> mx;
            for (auto& [g, ids] : grp) {
                int r = 0;
                for (int i : ids)
                    r = max(r, rank[i]);
                for (int i : ids)
                    mx[i] = r + 1;
            }

            for (auto& [i, j] : cells) {
                res[i][j] = mx[i];
                rank[i] = res[i][j];
                rank[j + m] = res[i][j];
            }
        }
        return res;
    }
};
