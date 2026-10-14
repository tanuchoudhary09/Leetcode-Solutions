class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if(sum > num * 9) return ans;
        for(int i=0;i<num;i++){
            if(sum >= 9){
                ans += '9';
                sum -= 9;
            }else{
                ans += ('0' + sum);
                sum -= sum;
            }
        }
        return ans;
    }
};