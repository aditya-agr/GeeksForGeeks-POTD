class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int n = mat.size();
        int m = mat[0].size();
        int i=0, j=m-1;
        while(i<n && j>=0){
            if(mat[i][j] > x)
                j--;
            else if(mat[i][j] < x)
                i++;
            else 
                return true;
        }
        return false;
    }
};