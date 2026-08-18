class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> fq(51, 0);
        for (int x : nums) fq[x]++;
        // int mx = INT_MIN;
        int ans = -1;
        auto mx_val = max_element(nums.begin(), nums.end());
        int mx = *mx_val;
        if (k == 1) {
            for (int i = 50; i >= 0; i--) {
                if (fq[i] == 1)
                    return i;
            }
            return -1;
            // else return -1;
        } else if (k == n)
            return mx;
        //     //else return -1;
        else {
            if (fq[nums[0]] == 1) {
                ans = max(ans, nums[0]);
            }
            if (fq[nums[n - 1]] == 1) {
                ans = max(ans, nums[n - 1]);
            }
            return ans;
        }
    return -1;
}
};