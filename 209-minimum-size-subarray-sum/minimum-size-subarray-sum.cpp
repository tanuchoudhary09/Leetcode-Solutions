class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,min_len=INT_MAX,sum=0,len;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                len=j-i+1;
                sum-=nums[i];
                min_len=min(min_len,len);
                i++;
            }
            j++;
        }
        if(min_len==INT_MAX) return 0;
        return min_len;
    }
};