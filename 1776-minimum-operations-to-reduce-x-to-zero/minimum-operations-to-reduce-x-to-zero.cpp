class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int cntl = 0;
        int ans = INT_MAX;
        int cntr = 0;
        if(nums[0]>x && nums[n-1]>x) return -1;
        unordered_map<int,int>m;
        m[0] = 0;
        for(int i=n-1;i>=0;i--){
            cntr += nums[i];
            if(cntr>x) break;
            m[cntr] = n-i;
        }
        if(m.count(x)) ans = m[x];
        for(int i=0;i<n;i++){
            cntl += nums[i];
            if(cntl>x) break;
            int val = x-cntl;
            if(m.count(x-cntl)){
                int len1 = m[val];
                int len2 = i+1;
                if(len1+len2<=n) ans = min(ans,len1+len2);
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};