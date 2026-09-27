class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<char> st;
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                string t = "";
                while(!st.empty() && st.top()!='(') {
                    t+=st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
                for(int j=0;j<t.length();j++){
                    st.push(t[j]);
                }
            }
            else st.push(s[i]);
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};