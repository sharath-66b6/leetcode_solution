class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int r=n-1;
        int l=0;
        while(r>0 && arr[r] >= arr[r-1])
        {
            r--;

        }
        int res=r;
        while(l<r && (l==0 || arr[l-1] <= arr[l]))
        {
            while(r<n && arr[l] > arr[r])
            {
                r++;
            }
            res = min(res,r-l-1);
            l++;
        }
        return res;
    }
};