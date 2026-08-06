class Solution {
public:
    int smallestNumber(int n, int t) {
        bool flag = true;
        while(1){
            int a = n;
            int p = a%10;
            a=a/10;
            while(a>0){
                p*=(a%10);
                a=a/10;
            }
            if(p%t==0)break;
            n++;
        }
        return n;
    }
};