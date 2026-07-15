class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i =0;i<n-1;i++){
            if(!nums[i]){
                bool flag = false;
                for(int j =i;j>=0;j--){
                    if(nums[j]>(i-j)){
                        flag=true;break;
                    }
                }
                if(!flag) return false;
            }
        }
        return true;
    }
};
//stack-no
//sliding window-no
//maths
// greedy