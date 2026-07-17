class Solution {
public:
    void ss(vector<int>nums,vector<int>v,set<vector<int>>&st,int idx){
        if(nums.size()==idx){
            st.insert(v);return;
        }
        ss(nums,v,st,idx+1);
        v.push_back(nums[idx]);
        ss(nums,v,st,idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>v;
        set<vector<int>>st;
        vector<vector<int>>ans;
        ss(nums,{},st,0);
        for(auto x:st){
            ans.push_back(x);
        }
        return ans;
    }
};