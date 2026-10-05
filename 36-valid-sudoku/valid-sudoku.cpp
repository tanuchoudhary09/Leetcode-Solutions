class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_set<char>s1,s2;
            for(int j = 0; j < 9; j++){
                if(board[i][j]!='.' && s1.count(board[i][j])) return false;
                if(board[j][i]!='.' && s2.count(board[j][i])) return false;
                s1.insert(board[i][j]);
                s2.insert(board[j][i]);
            }
        }
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                unordered_set<char>s;
                for(int x = 0; x < 3; x++){
                    for(int y = 0; y < 3; y++){
                        if(board[i+x][y+j]!='.' && s.count(board[i+x][y+j])) return false;
                        s.insert(board[x+i][y+j]);
                    }
                }
            }
        }
        return true;
    }
};