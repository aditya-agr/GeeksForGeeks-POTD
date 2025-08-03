class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        
        for(vector<int> o : opr){
            int v = o[0];
            int r1 = o[1], c1 = o[2];
            int r2 = o[3], c2 = o[4];
            res[r1][c1] += v;
            if(c2+1<m) res[r1][c2+1] -= v;
            if(r2+1<n) res[r2+1][c1] -= v;
            if(c2+1<m && r2+1<n) res[r2+1][c2+1] += v;
        }
        for(int i=1; i<n; i++)
            for(int j=0; j<m; j++)
                res[i][j] += res[i-1][j];
        
        for(int i=0; i<n; i++)
            for(int j=1; j<m; j++)
                res[i][j] += res[i][j-1];
                
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                mat[i][j] += res[i][j];
        }
        return mat;
    }
};