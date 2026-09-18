class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int T) {
        int sum = 0;
        int mn = INT_MAX;
        vector<int> helper(arr.size(), INT_MAX);
        for (int i = 0, j = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum > T) {
                while (sum > T) {
                    sum -= arr[j];
                    j++;
                }
            }
            if (sum == T)
                mn = min(i - j + 1, mn);
            helper[i] = mn;
        }
        sum = 0;
        mn = INT_MAX;
        int ans = INT_MAX;
        for (int i = arr.size() - 1, j = i; i > 0; i--) {
            sum += arr[i];
            if (sum > T) {
                while (sum > T) {
                    sum -= arr[j];
                    j--;
                }
            }
            if (sum == T)
                mn = min(j - i + 1, mn);
            if( mn != INT_MAX&& helper[i-1]!=INT_MAX)ans = min(ans, mn + helper[i-1]);
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};