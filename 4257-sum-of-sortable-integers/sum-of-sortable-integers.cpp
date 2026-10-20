class Solution {
public:
    bool check(vector<int>& nums, vector<int>& num, int& k){
        int n = nums.size();
        for(int i = 0; i < n; i+=k){
            int pvt = 0;
            int idx = 0;
            if(nums[i] < nums[i+k-1]) pvt++;
            for(int j = 0; j < k - 1; j++){
                if(nums[i+j] > nums[i+j+1]) {
                    idx = j + 1;
                    pvt++;
                }
                if(pvt > 1) return false;
            }
            for(int j = 0; j < k ; j++){
                if(nums[i+(idx+j)%k] != num[i+j]) return false;
            }
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> num = nums;
        sort(num.begin(),num.end());
        for(int k = 1; k <= n/2; k++){
            if(n % k == 0 && check(nums,num,k)) ans += k;
        }
        if(check(nums,num,n)) ans += n;
        return ans;
        
    }
};