class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int x : nums){
            int idx = abs(x)-1;
            if(nums[idx]<0) return idx+1;
            else nums[idx] = -nums[idx];
        }
        return 0;
    }
};