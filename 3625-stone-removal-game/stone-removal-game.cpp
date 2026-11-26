class Solution {
public:
    bool canAliceWin(int n) {
        int sum = 0;
        int k = 10;
        while(n >= k){
            sum++;
            n = n - k;
            k--;
        }
        return sum % 2;
    }
};