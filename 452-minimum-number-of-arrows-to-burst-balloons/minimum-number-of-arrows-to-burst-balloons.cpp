bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
         int ans = 0,n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int t = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=t) ans++;
            else t = intervals[i][1];
        }
        return n-ans;
    }
};