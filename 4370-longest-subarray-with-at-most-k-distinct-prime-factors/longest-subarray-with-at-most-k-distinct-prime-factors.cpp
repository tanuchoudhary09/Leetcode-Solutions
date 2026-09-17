class Solution {
    vector<vector<int>> fillsieve(int mx){
        vector<vector<int>> pf(mx+1);
        for(int i=2;i<=mx;i++){
            if(pf[i].size()==0){
                for(int j=i;j<=mx;j=j+i) pf[j].push_back(i);
            }
        }
        return pf;
    }
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        vector<vector<int>>pf = fillsieve(mx);
        int sz = 0;
        int j = 0;
        int ans = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for (auto p : pf[nums[i]]){
                if(mp[p] == 0) sz++;
                mp[p]++;
            }
            while(sz>k){
                for (auto p : pf[nums[j]]){
                    mp[p]--;
                    if(mp[p] == 0) sz--;
                }
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};