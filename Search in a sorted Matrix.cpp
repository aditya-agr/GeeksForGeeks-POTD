
class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size(), m = mat[0].size();
        int l = 0, h=n*m-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            int i = mid/m;
            int j = mid%m;
            if(mat[i][j] < x)
                l = mid+1;
            else if(mat[i][j] > x)
                h = mid-1;
            else 
                return true;
        }
        return false;
    }
};