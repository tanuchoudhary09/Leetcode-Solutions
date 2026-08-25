class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int>s;
        for(int x : nums) s.insert(x);
        int i = 1;
        while(1){
            if(!s.count(k*i)) return k*i;
            i++;
        }
        return 1;
    }
};