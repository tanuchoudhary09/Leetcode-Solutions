class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lw, int up) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(nums[i]<lw || nums[i]>up)continue;
            int mn = lw;
            int mx = min(nums[i]-1,up);
            if(mn<=mx) ans.push_back({mn,mx});
            lw = nums[i]+1;
        }
        if(lw<=up)ans.push_back({lw,up});
        return ans;
        
    }
};