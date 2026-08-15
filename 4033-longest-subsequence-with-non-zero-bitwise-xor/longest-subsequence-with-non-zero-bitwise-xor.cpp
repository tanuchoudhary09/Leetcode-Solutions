class Solution {
public:
//couldnt do myself
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int h = 0;
        bool check = true;
        for(int x : nums){
            h = h^x;
            if(x>0) check =false;
        }
        if(h>0) return n;
        if(check) return 0;
        return n-1; //reveersing the XOR
    }
};