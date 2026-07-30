class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int sum= 0;
        for(int i=0;i<n;i++){
            sum += i/8+1;
        }
        return sum;
    }
};