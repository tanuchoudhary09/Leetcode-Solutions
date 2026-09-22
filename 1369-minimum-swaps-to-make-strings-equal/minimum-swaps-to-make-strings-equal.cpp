class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.length();
        int cntx = 0, cnty = 0;
        int v1 = 0,v2 = 0;
        for(int i = 0; i < n; i++){
            if(s1[i]=='x') cntx++;
            else cnty++;
            if(s2[i]=='x') cntx++;
            else cnty++;
            if(s1[i]=='x' && s2[i]=='y') v1++;
            else if(s1[i]=='y' && s2[i]=='x') v2++;
        }
        std::cout<<cntx<<" "<<cnty;
        if(cntx%2!=0 || cnty%2!=0) return -1;
        return v1/2 + v2/2 + (v1%2)*2;
    }
};