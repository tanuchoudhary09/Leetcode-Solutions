class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int lo = 0,hi = n-1;
        while(lo<=hi){
            int mid = lo +(hi-lo)/2;
            int val = citations[mid];
            if(n-mid>val) lo=mid+1;
            else hi=mid-1;
        }
        return n-lo;
    }
};