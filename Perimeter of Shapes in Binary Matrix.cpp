
class Solution {
  public:
    int findPerimeter(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int peri=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    peri+=4;
                    if(i>0 && mat[i-1][j])
                      peri-=2;
                    if(j>0 && mat[i][j-1])
                      peri-=2;
                }
            }
        }
        return peri;
    }
};