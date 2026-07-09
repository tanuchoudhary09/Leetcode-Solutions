class Solution {
public:
    bool isNumber(string s) {
        int n = s.length(),count1=0,count3=0,idx=-1;
        bool flag1= false, flag2=true;
        if(s[n-1]=='e' || s[n-1]=='E') return false;
        if (s[n-1] == '+' || s[n-1] == '-') return false;
        if(n==1){
            if(s[0]>='0' && s[0]<='9') return true;
            else return false;
        }
        for(int i=0;i<n;i++){
            if(i==0){
                if(s[0]=='-' || s[0]=='+' || s[0]=='.' || (s[0]>='0' && s[0]<='9')){}
                else return false;
                if(s[0]=='-'){
                    if((s[1]>='0' && s[1]<='9')  || s[1]=='.'){}
                    else return false;
                }
                if(s[0]=='+'){
                    if((s[1]>='0' && s[1]<='9') ||  s[1]=='.'){}
                    else return false;
                }
                if(s[0]=='.'){
                    count3=1;
                    if(s[1]>='0' && s[1]<='9' ){}
                    else return false;
                }
                if(s[0]>='0' && s[0]<='9'){
                    flag1= true;
                    flag2= true;
                    if( s[1]=='e' || s[1]=='E'|| (s[1]>='0' && s[1]<='9') || s[1]=='.'){}
                    else return false;
                }
            }
            else{
                if(s[i]=='+' || s[i]=='-'){
                    if(s[i-1]=='e' || s[i-1]=='E'){
                        if(i+1>=n || s[i+1]<'0' || s[i+1]>'9') return false;
                    }
                    else return false;
                }
                else if(s[i]=='e' || s[i]=='E'){
                    if (!flag1) return false; 
                    count1++;
                    idx=i;
                    flag2=false;
                }
                else if(s[i]=='.') {
                    if(i+1!=n && (s[i+1]=='e'|| s[i+1]=='E') && !flag1) return false;
                    if(i>idx && idx!=-1) return false;
                    count3++;
                }
                else if(s[i]>'9' || s[i]<'0') return false;
                else{
                    flag1 = true;flag2 = true;
                }
                if(count1>1 || count3>1) return false; 
            }
            
        }
        return flag1 && flag2;
    }
};