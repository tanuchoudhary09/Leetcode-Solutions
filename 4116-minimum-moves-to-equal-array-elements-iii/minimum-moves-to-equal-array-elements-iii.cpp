class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int mx = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] <= mx) ans += (mx-nums[i]);
            else{
                ans += (nums[i]-mx) * i;
                mx = nums[i];
            }
        }
        return ans;
    }
};