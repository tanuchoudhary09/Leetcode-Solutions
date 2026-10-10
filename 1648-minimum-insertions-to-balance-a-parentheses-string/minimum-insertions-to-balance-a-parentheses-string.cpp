class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int open = 0;
        int close = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') open++;
            else {
                if(i+1<n && s[i+1]==')'){
                    i++;
                    if(open>0) open--;
                    else close++; 
                }else{
                    if(open>0){
                        open--;
                        close++;
                    }else close += 2;
                }
            }
        }
        //if(s[n-1]=='(') open += 2;
        return open*2 + close;
    }
};