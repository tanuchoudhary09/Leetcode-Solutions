class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int count=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0) count++;
            std::cout<<count;
        }
        int k = count;
        std::cout<<n-1-count;
        for(int i = n-1;i>n-1-k;i--){
            if(nums[i]==0) count--;
            std::cout<<count;
            std::cout<<i;
        }
        return count;
    }
};