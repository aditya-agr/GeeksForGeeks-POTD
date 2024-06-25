class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        k %= m;
        k = m-k;
        vector<vector<int>> res(n, vector<int>(m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                res[i][(j+k)%m] = mat[i][j];
        return res;
    }
    