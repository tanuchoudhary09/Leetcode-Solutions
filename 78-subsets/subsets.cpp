class Solution {
public:
    void ss(vector<int>nums,vector<vector<int>>&v,vector<int>h,int idx){
        if(idx==nums.size()){
            v.push_back(h);
            return;
        }
        ss(nums,v,h,idx+1);
        h.push_back(nums[idx]);
        ss(nums,v,h,idx+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>v;
        ss(nums,v,{},0);
        return v;
    }
};