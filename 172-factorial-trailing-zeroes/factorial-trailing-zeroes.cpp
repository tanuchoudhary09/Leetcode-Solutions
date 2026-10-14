class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0) return 0;
        int count = 0;
        for(int i = 1; i <= n ; i++){
            int j = i;
            while(j != 0 && j % 5 == 0){
                count++;
                j/=5;
            }
        }
        return count;
    }
};