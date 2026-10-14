class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        int val = 0;
        while(num--){
            int k = 10;
            while(k--){
                if(val + k > sum) continue;
                else {
                    //std::cout<<val + k <<" ";
                    ans += to_string(k);
                    val += k;
                    break;
                }
            }
        }
        if(val!=sum) return "";
        return ans;
    }
};