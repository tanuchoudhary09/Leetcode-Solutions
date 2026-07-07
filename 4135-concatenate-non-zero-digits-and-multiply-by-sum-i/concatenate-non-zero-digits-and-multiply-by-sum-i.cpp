class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long k = 1, x = 0;
        while(n>0){
            if(n%10!=0){
                x += (n%10)*k;
                k=k*10;
                sum+=n%10;
            }
            n=n/10;
        }
        return (int)x*sum;
    }
};