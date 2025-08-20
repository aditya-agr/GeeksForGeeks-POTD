class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int l = 0, h = n*m-1;
        while(l <= h){
            int mid = l+(h-l)/2;
            int num = mat[mid/m][mid%m];
            int numl = mat[l/m][l%m];
            int numh = mat[h/m][h%m];
            if(num == x){
                return true;
            }
            if(numl <= num){
                if(x<num && x>=numl)
                    h = mid-1;
                else
                    l = mid+1;
            }
            else{
                if(x>num && x<=numh)
                    l = mid+1;
                else
                    h = mid-1;
            }
        }
        return false;
    }
};
