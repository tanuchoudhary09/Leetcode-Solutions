class Solution {
    bool flag = false;
public:
    
    void dfs(int r, int c, string &word, vector<vector<char>>&board, string &helper, vector<int>&dc, vector<int>&dr,int k){
        if(flag) return;
        helper += board[r][c];
        if(helper==word) {
            flag=true;return;
        }
        char temp = board[r][c]; //we keep this to restore the board again
        board[r][c] = '#';
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if( nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() && k+1<word.length() && board[nr][nc] == word[k+1]) {
                dfs(nr,nc,word,board,helper,dc,dr,k+1);
            }
            
        }
        board[r][c] = temp;//here we restore
        helper.pop_back();//backtrack
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int c = word[0];
        string helper = "";
        vector<int>dr = {-1,0,1,0};
        vector<int>dc = {0,1,0,-1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==c) dfs(i,j,word,board,helper,dr,dc,0);
                if(flag) return true;
            }
        }
        return flag;
    }
};