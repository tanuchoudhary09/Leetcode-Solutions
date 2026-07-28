bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n = intervals.size();
        vector<vector<int>>ans;
        ans.push_back(intervals[n-1]);
        //sort(intervals.begin(),intervals.end(),cmp);
        //std::cout<<intervals[0][1]<<intervals[1][1];
        for(int i=n-2;i>=0;i--){
            //vector<int>&lI=ans[ans.size()-1];
            vector<int>curr = intervals[i];
            if(curr[1]>=ans[ans.size()-1][0]){
                ans[ans.size()-1][0]=min(ans[ans.size()-1][0],curr[0]);
                ans[ans.size()-1][1]=max(ans[ans.size()-1][1],curr[1]);
            }else ans.push_back(intervals[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};