class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int m = nums.size();
        int n = nums[0].size();
        int hi = n-1;
        int i = 0;
        while(i<m && hi>=0){
            if(nums[i][hi]==target) return true;
            else if(nums[i][hi]>target) hi--;
            else i++;
        }
        return false;
    }
};