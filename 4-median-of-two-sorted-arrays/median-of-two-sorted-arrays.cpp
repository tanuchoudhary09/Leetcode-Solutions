class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        vector<int> v;
        while (i < n && j < m) {
            if (nums1[i] > nums2[j]) v.push_back(nums2[j++]);
            else v.push_back(nums1[i++]);
        }
        while (i < n) v.push_back(nums1[i++]);
        while (j < m) v.push_back(nums2[j++]);
        int k = v.size();
        if (k % 2 == 1) return v[k / 2];
        return (v[k / 2 - 1] + v[k / 2]) / 2.0;
    }
};