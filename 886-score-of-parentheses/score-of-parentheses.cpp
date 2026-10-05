class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int curr = 0;
        for(char c : s){
            if(c=='('){
                st.push(curr);
                curr = 0;
            }else{
                int val = st.top();
                st.pop();
                int score = (curr==0)?1:2*curr;
                curr = val + score; 
            }
        }
        return curr;
    }
};