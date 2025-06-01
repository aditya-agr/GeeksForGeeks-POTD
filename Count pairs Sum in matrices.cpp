class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int target) {
        // code here
        int n = mat1.size();
        int i=0, j=0, x=n-1, y=n-1;
        int cnt = 0;
        while(i<n && j<n && x>=0 && y>=0){
            int sum = mat1[i][j] + mat2[x][y];
            if(sum == target){
                cnt++;
                j++;
                if(j == n){
                    i++;
                    j=0;
                }
            }
            else if(sum < target){
                j++;
                if(j == n){
                    i++;
                    j=0;
                }
            }
            else{
                y--;
                if(y < 0){
                    y = n-1;
                    x--;
                }
            }
        }
        return cnt;
    }
};