class Solution {
  public:
    int largestSubsquare(vector<vector<char>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp1(n, vector<int>(m));
        vector<vector<int>> dp2(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 'X'){
                    dp1[i][j] = 1;
                    if(j>0)
                        dp1[i][j] += dp1[i][j-1];
                }
            }
        }
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                if(mat[i][j] == 'X'){
                    dp2[i][j] = 1;
                    if(i>0)
                        dp2[i][j] += dp2[i-1][j];
                }
            }
        }
        int ans = 0;
        for (int i=n-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                int possible = min(dp1[i][j], dp2[i][j]);
                while (possible > ans) {
                    int topRow = i - possible + 1;
                    int leftCol = j - possible + 1;
                    bool top = dp1[topRow][j] >= possible;
                    bool leftSide = dp2[i][leftCol] >= possible;
    
                    if (top && leftSide) {
                        ans = possible;
                        break;
                    }
                    possible--;
                }
            }
        }
        return ans;
    }
};