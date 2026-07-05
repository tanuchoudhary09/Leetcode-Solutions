class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = INT_MIN;
        int ans = INT_MIN;
        for(int i=n-1;i>=k;i--){
            mx = max(mx,nums[i]);
            ans = max(nums[i-k]+mx,ans);
        }
        return ans;
    }
};