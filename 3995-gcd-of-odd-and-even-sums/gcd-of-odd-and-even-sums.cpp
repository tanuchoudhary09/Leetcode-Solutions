class Solution {
public:
    int gcd(int a,int b){
        while(b!= 0){
        int rem = a%b;
        a = b;
        b = rem;
    }
    return a;
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0,sumEven=0;
        for(int i=1;i<=2*n;i++){
            if(i%2) sumOdd+=i;
            else sumEven+= i;
        }
        return gcd(sumOdd,sumEven);
    }
};