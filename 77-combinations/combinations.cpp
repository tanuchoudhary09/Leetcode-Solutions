class Solution {
public:
    void solve(vector<int>&v,vector<int>&h,vector<vector<int>>&ans,int idx,int k,int n){
        if(h.size()==k){
            ans.push_back(h);
            return;
        }
        if(idx==n) return;
        if((h.size()+n-idx)<k) return;
        solve(v,h,ans,idx+1,k,n);
        h.push_back(v[idx]);
        solve(v,h,ans,idx+1,k,n);
        h.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v,h;
        for(int i=1;i<=n;i++) v.push_back(i);
        solve(v,h,ans,0,k, n);
        return ans;
    }
};