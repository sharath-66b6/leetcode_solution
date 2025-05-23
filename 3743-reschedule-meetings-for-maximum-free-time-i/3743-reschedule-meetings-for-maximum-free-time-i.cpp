class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        startTime.push_back(eventTime);
        endTime.insert(endTime.begin(),0);
        int n = startTime.size();
        vector<int> dif(n, 0);
        for(int i=0;i<n;i++){
            dif[i] = startTime[i] - endTime[i];
            // cout<<dif[i]<<" ";
        }
        int i=0,mx=0,sum=0;
        for(int j=0;j<n;j++){
            if(j-i > k){
                sum -= dif[i];
                i++;
            }
            sum += dif[j];
            mx = max(mx, sum);
        }
        return mx;
    }
};