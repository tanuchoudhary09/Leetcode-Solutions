class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) nums[i] = abs(nums[i]);
        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        long long sum = 0;
        while(j > i){
            sum += (nums[j] * nums[j]) - (nums[i] * nums[i]);
            j--;i++;
        }
        if(n % 2!=0) sum += nums[j] * nums[j];
        return sum;
    }
};