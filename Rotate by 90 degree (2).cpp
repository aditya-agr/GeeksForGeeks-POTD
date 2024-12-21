class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n-i; j++){
                int ni = n-1-j;
                int nj = n-1-i;
                swap(mat[i][j], mat[ni][nj]);
            }
        }
        for(vector<int> &x : mat){
            reverse(x.begin(), x.end());
        }
    }
};