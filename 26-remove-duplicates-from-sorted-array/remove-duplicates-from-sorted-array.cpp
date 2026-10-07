class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 1, cnt = 0;
        for(int i = 1; i < n; i++){
            if(nums[i]!=nums[i-1]){
                nums[j] = nums[i];
                j++;
            }else cnt++;
        }
        //j++;
        //nums[j] = nums[n-1];
        return j;
    }
};