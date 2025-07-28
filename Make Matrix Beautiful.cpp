class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row(n), col(m);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }
        int mx = 0;
        for(int i=0; i<n; i++)
            mx = max(mx, row[i]);
        for(int j=0; j<m; j++)
            mx = max(mx, col[j]);
        
        for(int i=0; i<n; i++)
            row[i] = mx - row[i];
        for(int j=0; j<m; j++)
            col[j] = mx - col[j];
            
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row[i] && col[j]){
                    int val = min(row[i], col[j]);
                    mat[i][j] += val;
                    cnt += val;
                    row[i] -= val;
                    col[j] -= val;
                }
            }
        }
        return cnt;
    }
};