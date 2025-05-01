class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long> mx(n, 0);
        stack<int> s1,s2;
        s1.push(-1);
        long long sum = 0;

        for (int i = 0; i < n; ++i) {
            sum = solve(s1, maxHeights, i, sum);
            mx[i] = sum;
        }

        
        s2.push(n);
        sum = 0;

        for (int i = n - 1; i >= 0; --i) {
            sum = solve(s2, maxHeights, i, sum);
            mx[i] += sum - maxHeights[i];
        }
        return *max_element(mx.begin(), mx.end());
    }

private:
    long solve(stack<int>& s, vector<int>& maxHeights, int i, long long sum) {
        while (s.size() > 1 && maxHeights[s.top()] > maxHeights[i]) {
            int j = s.top();
            s.pop();
            sum -= static_cast<long>(abs(j - s.top())) * maxHeights[j];
        }
        sum += static_cast<long>(abs(i - s.top())) * maxHeights[i];
        s.push(i);
        return sum;
    }
};