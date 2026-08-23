class Solution {
public:
    bool sumGame(string s) {
        int n = s.length();
        int left_sum = 0, right_sum = 0;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n / 2; i++) {
            if (s[i] == '?') cnt1++;
            else left_sum += s[i]-48;
        }
        for (int i = n / 2; i < n; i++) {
            if (s[i] == '?') cnt2++;
            else right_sum += s[i]-48;
        }
        // if (cnt1+cnt2==0) return left_sum != right_sum;
        if((cnt1+cnt2)%2!=0) return true;
        if(cnt1>cnt2){
            if(left_sum>right_sum) return true;
            if(right_sum-left_sum==((cnt1-cnt2)/2)*9) return false;
            else return true;
        }
        if(cnt2>cnt1){
            if(left_sum<right_sum) return true;
            if(0-right_sum+left_sum==((cnt2-cnt1)/2)*9) return false;
            else return true;
        }
        if(left_sum==right_sum) return false;
        return true;
    }
};