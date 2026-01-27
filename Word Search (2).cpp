class Solution {
  public:
    int n, m;
    vector<vector<int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};
    bool search(int idx, int x, int y, vector<vector<int>> &vis, string &s, vector<vector<char>> &mat){
        if(idx == s.length())
            return true;
        vis[x][y] = 1;
        
        for(vector<int> &d : dir){
            int x_ = x + d[0];
            int y_ = y + d[1];
            if(x_<0 || x_>=n || y_<0 || y_>=m || vis[x_][y_])
                continue;
            if(mat[x_][y_] == s[idx] && search(idx+1, x_, y_, vis, s, mat))
                return true;
        }
        vis[x][y] = 0;
        return false;
    }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        n = mat.size();
        m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == word[0] && search(1, i, j, vis, word, mat)){
                    return true;
                }
            }
        }
        return false;
        
    }
};