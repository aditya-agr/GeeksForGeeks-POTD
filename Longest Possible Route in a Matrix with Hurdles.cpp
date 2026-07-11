class Solution {
  public:
    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int n, m;
    int res;
    void solve(int cur, vector<vector<int>>& mat, int x, int y, int xd, int yd){
        if(x == xd && y == yd){
            res = max(res, cur);
            return;
        }
        mat[x][y] = 0;
        for(vector<int> &d : dir){
            int x_ = x + d[0];
            int y_ = y + d[1];
            if(x_<0 || x_>=n || y_<0 || y_>=m || mat[x_][y_]==0)
                continue;
            solve(cur+1, mat, x_, y_, xd, yd);
        }
        mat[x][y] = 1;
    }
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // code here
        n = mat.size();
        m = mat[0].size();
        
        if(mat[xs][ys] == 0)
            return -1;
        res = -1;
        solve(0, mat, xs, ys, xd, yd);
        return res;
    }
};