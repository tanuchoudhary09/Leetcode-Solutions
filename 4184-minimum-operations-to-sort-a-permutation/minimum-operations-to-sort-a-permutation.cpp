class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), pvt = 0;
        if(nums[0] < nums[n-1]) pvt++;
        int idx = -1;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i+1]) {
                idx = i;
                pvt++;
            }
            if(pvt > 1) {
                idx = -2;
                break;
            }
        }
        reverse(nums.begin(),nums.end());
        pvt = 0;
        int idx1 = -1;
        if(nums[0] < nums[n-1]) pvt++;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i+1]) {
                idx1 = i;
                pvt++;
            }
            if(pvt > 1) {
                idx1 = -2;
                break;
            }
        }
        if(idx == -2 && idx1 == -2) return -1;
        int og = (idx==-1)? 0 : (idx + 1);
        int rev = (idx1==-1)? 0 : (idx1 + 1);
         int ans = INT_MAX;
        if (idx != -2) ans = min(min(ans, og), n - og + 2);
        if (idx1 != -2) ans = min(min(ans, rev + 1), n - rev + 1);
        return ans;
    }
};