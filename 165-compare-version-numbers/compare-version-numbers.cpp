class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n = v1.length(), m = v2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            int num1 = 0;int num2 = 0;
            while (i < n && v1[i] != '.') {
                num1 = num1 * 10 + (v1[i] - '0');
                i++;
            }
            while (j < m && v2[j] != '.') {
                num2 = num2 * 10 + (v2[j] - '0');
                j++;
            }
            i++;j++;
            if (num1 > num2) return 1;
            if (num1 < num2) return -1; 
        }
        
        return 0;
    }
};