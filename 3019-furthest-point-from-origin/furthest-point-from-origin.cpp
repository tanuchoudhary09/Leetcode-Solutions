class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        //int n = s.length();
        int ans = 0;
        int cnt = 0;
        for(char c : moves){
            if(c == 'L') ans++;
            else if(c == 'R') ans--;
            else cnt++;
        }
        return abs(ans) + cnt;
    }
};