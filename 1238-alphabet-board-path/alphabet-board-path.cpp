class Solution {
public:
    string alphabetBoardPath(string target) {
        int curr1 = 0, curr2 = 0;
        string ans = "";
        for(char ch : target){
            int idx = ch-'a';
            int r = idx/5, c = idx % 5;
            int path1 = curr1 - r;
            int path2 = curr2 - c;
            curr1 = r;
            curr2 = c;
            char appnd1 = 'U',appnd2 = 'L';
            if(path1<0) appnd1 = 'D';
            if(path2<0) appnd2 = 'R';
            if(path1 > 0){
                for(int i = 0; i < abs(path1); i++) ans += appnd1;
                for(int i = 0; i < abs(path2); i++) ans += appnd2;
            } else {
                for(int i = 0; i < abs(path2); i++) ans += appnd2;
                for(int i = 0; i < abs(path1); i++) ans += appnd1;
            }
            ans += '!';
        }
        return ans;
    }
};