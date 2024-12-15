class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto improvement = [](int pass, int total) -> double {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        priority_queue<pair<double, pair<int, int>>> pq;

        for (auto& c : classes) {
            double imp = improvement(c[0], c[1]);
            pq.push({imp, {c[0], c[1]}});
        }

        while (extraStudents--) {
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first, total = top.second.second;
            pass++;
            total++;
            double newImp = improvement(pass, total);
            pq.push({newImp, {pass, total}});
        }

        double totalAvg = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first, total = top.second.second;
            totalAvg += (double)pass / total;
        }

        return totalAvg / classes.size();
    }
};
