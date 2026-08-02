class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans=LLONG_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int GCD=gcd(nums[i],nums[j]);
                ans=max(ans,(long long)nums[i]*nums[j]/GCD/GCD); 
            }
        }
        return ans;;
    }
};