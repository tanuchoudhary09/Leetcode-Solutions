class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return nums[0]+k;
        priority_queue<int,vector<int>,greater<int>> mH(nums.begin(),nums.end());//n
        //for(int num:nums) mH.push(num);  nlogn
        while(k--){
           int temp = mH.top();
           mH.pop();mH.push(temp+1);
        }
        long long ans=1, mod = 1e9+7;
        int sz = mH.size();
        while(sz--){
            ans = (ans*mH.top())%mod; mH.pop();
        } 
        return (int)ans;       
    }
};