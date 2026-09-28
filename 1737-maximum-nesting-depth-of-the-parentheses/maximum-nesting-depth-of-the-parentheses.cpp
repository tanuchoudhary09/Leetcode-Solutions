class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, mx = 0;
        for(char c : s){
            if(c=='(') cnt++;
            else if(c==')'){
                mx = max(cnt,mx);
                cnt--;
            }
        }
        return mx;
    }
};