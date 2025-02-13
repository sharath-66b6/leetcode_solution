class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> q;
        for(auto i:nums){
            if(i < k)
                q.push(i);
        }

        int res = 0;
        while(q.size() >= 2){
            long long i = q.top();
            q.pop();
            long long j = q.top();
            q.pop();

            long long x = min(i,j)*2 + max(i,j);
            if(x < k)
                q.push(x);
            
            res++;
        }
        if(!q.empty())
            res++;

        return res;

    }
};