class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int idx1=-1,idx2=-1;
        int mx = INT_MIN;
        int mn = INT_MAX;
        int val1 = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            if(mx==nums[i]) idx1 = i;
            mn = min(mn,nums[i]);
            if(mn==nums[i]) idx2 = i;
        }
        if(idx1>idx2) val1 = min(idx1+1,n-idx2);
        else val1 = min(idx2+1,n-idx1);
        int val2 = min(idx1+1+n-idx2,n-idx1+idx2+1);
        return min(val1,val2);
    }
};