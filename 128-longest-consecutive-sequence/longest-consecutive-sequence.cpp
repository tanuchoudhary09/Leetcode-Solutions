class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int>s(nums.begin(),nums.end());
        int mx = 1;
        for(int x : s){
            if(!s.count(x-1)){
                int len = 0;
                while(s.count(x++)) len++;
                mx = max(len,mx);
            }
        }
        return mx;
    }
};