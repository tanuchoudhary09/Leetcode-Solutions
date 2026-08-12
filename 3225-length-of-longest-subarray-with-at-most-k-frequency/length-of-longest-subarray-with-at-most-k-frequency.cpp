class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int j = -1;
        int len = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n && j < n; i++){
            m[nums[i]]++;
            while(m[nums[i]]>k) {
                j++;
                m[nums[j]]--;
            }
            len = max(i-j,len);
        }
        return len;
    }
};