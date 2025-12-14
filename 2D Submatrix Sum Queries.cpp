class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> pre(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pre[i][j] = mat[i][j];
                if(j>0) pre[i][j] += pre[i][j-1];
            }
            for(int j=m-1; j>=0; j--)
                if(i>0) pre[i][j] += pre[i-1][j];
        }
        vector<int> res;
        for(vector<int> q : queries){
            int r1 = q[0];
            int c1 = q[1];
            int r2 = q[2];
            int c2 = q[3];
            int ans = pre[r2][c2];
            if(r1>0) ans -= pre[r1-1][c2];
            if(c1>0) ans -= pre[r2][c1-1];
            if(r1>0 && c1>0) ans += pre[r1-1][c1-1];
            
            res.push_back(ans);
        }
        return res;
    }
};
