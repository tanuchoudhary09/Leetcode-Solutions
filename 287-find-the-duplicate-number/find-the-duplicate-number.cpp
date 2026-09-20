class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 1;
        int hi = n-1;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid) cnt++;// we check the cnt of total numbers upto mid and check if there are mid numbers if not then there are more number from mid to hi so we take lo = mid+1
            }
            if(cnt<=mid) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};