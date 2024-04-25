
class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // code here
        if(n<3 or m<3)return -1;
        int ans = INT_MIN;
        for(int i=2;i<n;i++){
            int sum=0;
            for(int j=1;j<m-1;j++){
                sum = mat[i-2][j-1]+mat[i-2][j]+mat[i-2][j+1]+mat[i-1][j]+mat[i][j-1]+mat[i][j]+mat[i][j+1];
                ans=max(sum,ans);
            }
        }
        return ans;
    }
};