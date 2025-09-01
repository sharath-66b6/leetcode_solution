class Solution {
    struct Compare {
        bool operator()(const tuple<double,int,int> &t1,
                        const tuple<double,int,int> &t2) const {
            return get<0>(t1) < get<0>(t2);
        }
    };
    
    double gain(int a, int b) {
        return (double)(a+1)/(b+1) - (double)a/b;
    }
    
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<
            tuple<double,int,int>,
            vector<tuple<double,int,int>>,
            Compare
        > pq;

        for (auto &v : classes) {
            pq.push({gain(v[0], v[1]), v[0], v[1]});
        }

        while (extraStudents--) {
            auto [g, a, b] = pq.top();
            pq.pop();
            a++; b++;
            pq.push({gain(a, b), a, b});
        }

        double ans = 0;
        while (!pq.empty()) {
            auto [g, a, b] = pq.top(); pq.pop();
            ans += (double)a/b;
        }
        return ans / classes.size();
    }
};
