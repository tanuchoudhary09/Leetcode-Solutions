class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string>helper;
        string temp,ans="";
        while(ss>>temp){
            helper.push_back(temp);
        }
        int n = helper.size();
        for(int i = n-1;i>=0;i--){
            ans+=helper[i];
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};