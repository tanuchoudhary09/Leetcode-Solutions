class Solution {
public:
    int sum(int x){
        int y = 0;
        while(x>0){
            y = y+x%10;
            x = x/10;
        }
        return y;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(sum(x)==i) return i;
        }
        return -1;
    }
};