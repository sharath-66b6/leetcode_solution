class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        int n = events.size();
        int mxd = 0;
        for(int i=0; i<n; i++){
            mxd = max(mxd, events[i][1]);
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(events.begin(),events.end());
        int ans = 0;
        for(int i=0,j=0; i<=mxd; i++){
            while(j<n && events[j][0] <= i){
                pq.emplace(events[j][1]);
                j++;
            }
            while(!pq.empty() && pq.top() < i)
                pq.pop();
            
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
            
        }
        return ans;
    }
};