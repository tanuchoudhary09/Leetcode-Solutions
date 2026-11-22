class Solution {
public:
    bool checkString(string s) {
        int n = s.length(), idx_a = -1, idx_b = -1;
        for(int i = 0; i < n; i++){
            if(s[i]=='b'){
                idx_b = i;
                break;
            }
        }
        for(int i = n-1; i >= 0; i--){
            if(s[i]=='a'){
                idx_a = i;
                break;
            }
        }
        if(idx_a == -1 || idx_b == -1) return true;
        return idx_b > idx_a;
    }
};