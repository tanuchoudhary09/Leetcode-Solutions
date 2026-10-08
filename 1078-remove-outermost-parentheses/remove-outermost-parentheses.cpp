class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int open = 0;//, close = 0;
        bool flag;
        for(char c : s){
            flag = false;
            if(open == 0) flag = true;
            if(c=='(') open++;
            else open--;
            std::cout<<open;
            if(!flag && open>=1) ans += c;
        }
        return ans;
    }
};