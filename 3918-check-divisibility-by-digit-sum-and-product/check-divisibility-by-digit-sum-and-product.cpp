class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum = 0, product = 1;
        int x = n;
        while(n>0){
            sum+=(n%10);
            product*=(n%10);
            n = n/10;
        }
        //if(product == 0) return false;
        return (x %(sum+product))==0? true:false;
    }
};