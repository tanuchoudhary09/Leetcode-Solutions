class Solution {
public:
    int maxProduct(int n) {
        int mx1 = INT_MIN,mx2 = mx1;;
        while(n>0){
            int x = n%10;
            if(x>=mx1) {mx2=mx1;mx1=x;}
            else if(x>mx2 && x!=mx1) mx2 = x;
            n=n/10;
        }
        return mx1*mx2;
    }
};