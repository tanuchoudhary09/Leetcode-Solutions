class Solution {
public:
    //O(n) time
    vector<int> targetIndices(vector<int>& nums, int target) {
        int grt = 0;
        int small = 0;
        for(int x : nums){
            if(x > target) grt++;
            else if(x < target) small++;
        }
        int n = nums.size() - grt - small;
        vector<int>ans;
        for(int i = 0; i < n; i++) ans.push_back(i + small);
        return ans;
    }
};