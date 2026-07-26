class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size(),sum = 0;
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        for(int x:nums) sum+=x;
        while(k--){
            if(!pq.top()) break;
            int top = pq.top();
            pq.pop();
            pq.push(-top);
            sum = sum-2*top;//+(-top);
        }
        return sum;
    }
};