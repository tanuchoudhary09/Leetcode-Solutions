class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mn = INT_MAX;
        int ans = 0;
        for(int i=0;i<n;i++){
            int lo = i+1;
            int hi = n - 1;
            while(lo<hi){
                //int mid = lo + (hi - lo)/2;
                int sum = nums[lo] + nums[i] + nums[hi];//checks for closest pair w/ checking all pairs
                if(abs(sum-target)<mn){
                    mn = abs(sum-target);
                    ans = sum;
                }
                if(sum>target) {
                    //mn = min(mn,target-sum);
                    hi--;
                }
                else if(sum==target) return target;
                else{
                    //mn = min(mn,target-sum);
                    lo++;
                }
            }
        }
        return ans;
    }
};