class Solution {
public:
    int minOperations(string s) {
        if(is_sorted(s.begin(),s.end())) return 0;
        if(s.length() == 2) return -1;
        int mn = s[0], mx = s[0];
        for(int c : s){
            mn = min(mn,c);
            mx = max(mx,c);
        }
        if(mn==s[0] || mx==s[s.length()-1]) return 1;
        for(int i = 1; i < s.length()-1; i++){
            if(s[i]==mn || s[i]==mx) return 2;
        }
        return 3;
    }
};