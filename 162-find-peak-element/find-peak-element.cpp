class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(n==2){
            if(nums[1]>nums[0]) return 1;
            else return 0;
        }
        int lo = 0, hi = n-1;
        while(lo<=hi){
            if(nums[lo]<nums[lo+1]){
                if(nums[lo+1]>nums[lo+2]) return lo+1;
                else lo+=2;
            }else return lo;
            if(nums[hi]<nums[hi-1]){
                if(nums[hi-1]>nums[hi-2]) return hi-1;
                else hi-=2;
            }else return hi;
        }
        return 10;
    }
};