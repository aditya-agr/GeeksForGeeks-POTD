class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int n=matrix.size(), m=matrix[0].size(), res=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!matrix[i][j]){
                    if(i>0 && matrix[i-1][j]) res++;
                    if(i<n-1 && matrix[i+1][j]) res++;
                    if(j>0 && matrix[i][j-1]) res++;
                    if(j<m-1 && matrix[i][j+1]) res++;
                }
            }
        }
        return res;
    }
};