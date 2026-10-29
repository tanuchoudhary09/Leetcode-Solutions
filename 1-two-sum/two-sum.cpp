class Solution {
public:
    // using binary search O(logn)
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>>idx;
        for(int i = 0; i < n; i++) idx.push_back({nums[i],i});
        sort(idx.begin(),idx.end());
        int lo = 0;
        int hi = n-1;
        while(lo < hi){
            int sum = idx[hi].first+idx[lo].first;
            if(sum==target) return {idx[hi].second, idx[lo].second};
            else if(sum > target) hi--;
            else lo++;
        }
        return {};
    }
};