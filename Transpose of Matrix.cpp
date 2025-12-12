class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<vector<int>> res(n, vector<int>(n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                res[i][j] = mat[j][i];
        
        return res;
    }
};