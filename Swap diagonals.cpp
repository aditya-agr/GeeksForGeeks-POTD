class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int ri=0, rj=0, li=0, lj=n-1;
        for(int i=0; i<n; i++)
            swap(mat[ri++][rj++], mat[li++][lj--]);
    }
};
