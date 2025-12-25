class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> res;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                bool ispeak = true;
                if(i>0 && mat[i-1][j]>mat[i][j])
                    ispeak = false;
                if(i<n-1 && mat[i+1][j]>mat[i][j])
                    ispeak = false;
                if(j>0 && mat[i][j-1]>mat[i][j])
                    ispeak = false;
                if(j<m-1 && mat[i][j+1]>mat[i][j])
                    ispeak = false;
                
                if(ispeak)
                    return {i, j};
            }
        }
        return {-1,-1};
    }
};
