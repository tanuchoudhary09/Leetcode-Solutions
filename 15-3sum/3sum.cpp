class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            unordered_set<int>s;
            for(int j=i+1;j<n;j++){
                int t = -(nums[i]+nums[j]);
                if(s.count(t)){
                    ans.push_back({nums[i], nums[j], t});
                    while(j+1<n && nums[j]==nums[j+1]) j++;
                }
                s.insert(nums[j]);
            }
        }
        return ans;
    }
};
