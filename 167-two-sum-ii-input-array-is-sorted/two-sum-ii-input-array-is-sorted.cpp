class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        while(lo < hi){
            int sum = nums[lo] + nums[hi];
            if(sum == target) return{lo+1,hi+1};
            else if (sum > target) hi--;
            else lo++;
        }
        return {};
    }
};