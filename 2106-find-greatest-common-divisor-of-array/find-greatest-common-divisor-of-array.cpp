class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX,mx=INT_MIN;
        for(int x:nums){
            mn = min(mn,x);
            mx = max(mx,x);
        }
        return gcd(mn,mx);
    }
};