class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return 0;
        vector<int>mn(n);
        int mx = INT_MIN;
        mn[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--) mn[i] = min(mn[i+1],nums[i]);
        for(int i = 0;i<n;i++){
            mx = max(mx,nums[i]);
            //if(mn==nums[i]) idx1 =i;
            if(mx-mn[i]<=k) return i;
        }
        return -1;
    }
};