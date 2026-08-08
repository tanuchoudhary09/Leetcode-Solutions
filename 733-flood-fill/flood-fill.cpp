class Solution {
public:
    void dfs(vector<vector<int>>& image, int ini, int color,int r,int c){
        int n = image.size();
        int m = image[0].size();
        if((r<0 || c<0 || c>=m || r>=n)) return;
        if(ini!=image[r][c]) return;
        image[r][c]=color;
        dfs(image,ini,color,r+1,c);
        dfs(image,ini,color,r-1,c);
        dfs(image,ini,color,r,c+1);
        dfs(image,ini,color,r,c-1);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial = image[sr][sc];
        if(initial==color) return image;
        dfs(image,initial,color,sr,sc);
        return image;
    }
};