class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            vector<string>helper;
            int x = -1, y = 0;
            while(i < n && x + words[i].length() +1 <= maxWidth){
                helper.push_back(words[i]);
                x += words[i].length() +1;
                i++;
            }
            i--;
            int length = helper.size();
            string s = "";
            if(i==n-1 || length==1){
                for(int j = 0; j < length; j++) {
                    s += helper[j];
                    if(j < length - 1) s += ' ';
                }
                while(s.length() < maxWidth) s += ' ';
            }
            else{
                int ch = x - length +1;
                int left = maxWidth - ch;
                int gap = length - 1;
                int val = left/gap;
                int rem = left % gap;
                for(int j=0;j<length;j++){
                    s += helper[j];
                    if(j==length-1) break;
                    int k = val;

                    if(rem>0) {
                        k = val + 1;
                        rem--;
                    }
                    while(k--){
                        s += ' ';
                    }
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};