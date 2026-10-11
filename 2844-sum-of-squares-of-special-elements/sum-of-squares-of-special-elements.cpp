class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        long long sq_sum = 0;
        for(int i = 1; i <= n; i++){
            if(!(n % i)) sq_sum += (nums[i-1]*nums[i-1]);
        }
        return sq_sum;
    }
};