class Solution {
    long long pow(long long x,long long n){
        long long mod = 1e9+7;
        //long long  m=(n<0)?-n:n;
        if(n==0) return 1;
        long long k=pow(x,n/2);
        long long bs= (k*k)%(mod);
        if(n%2 == 0) return bs;
        else return (bs*(x%mod))%mod;
    }
    long long myPow(long long x, int n) {
        long long m=(long long)n; 
        return pow(x,m);
    }
public:
    int numberOfSets(int n, int k) {//we use the star and bars pnc formula|| can be done using pascal's triangle more comfortably
        int a = n+k-1;
        int b = 2*k;
        if(b>a) return 0;
        long long mod = 1e9+7;
        long long Nr = 1;
        long long Dr = 1;
        for(int i = 1; i <= b; i++){
            Nr = 1*Nr*a % mod;
            Dr = 1*Dr*i % mod;
            a--;
        }
        Dr = pow(Dr,mod-2);
        return (Nr*Dr)% mod;
    }
};
