class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==2) return 2;
        int cnt = 0;
        int j = 1;
        for(int i = 1; i < n; i++){
            if(nums[i]==nums[i-1]) cnt++;
            else cnt = 0;
            if(cnt<=1){
                nums[j] = nums[i]; 
                j++;
            }
        }
        return j;
    }
};