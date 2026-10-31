class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        //unordered_map<int,int>m;
        vector<vector<int>>ans;
        // for(int i = 0; i < n; i++) m[nums[i]] = i;
        for(int i = 0; i < n; i++){
            while(i >0 && i< n && nums[i]==nums[i-1]) i++;
            int lo = i + 1; 
            int hi = n - 1;
            while(lo < hi){
                int total = nums[i] + nums[lo] + nums[hi];
                if(total > 0) hi--;
                else if (total < 0) lo++;
                else{
                    ans.push_back({nums[i],nums[lo],nums[hi]});
                    lo++;
                    while(nums[lo]==nums[lo-1] && lo < hi) lo++;
                }
            }
        }
        return ans;
    }
};