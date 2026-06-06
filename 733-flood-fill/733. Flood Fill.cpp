class Solution {
    int oC, dC;
    int m, n;
    int adj[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void dfs(vector<vector<int>>& image, int r, int c) {
        image[r][c] = dC;
        for(int i=0; i<4; i++) {
            int x = r + adj[i][0];
            int y = c + adj[i][1];
            if(x >=0 && x < n && y >=0 && y < m && image[x][y] == oC) {
                dfs(image, x, y);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        oC = image[sr][sc];
        dC = color;
        if(oC == dC) return image;
        n = image.size(); m = image[0].size();
        dfs(image, sr, sc);
        return image;
    }
};