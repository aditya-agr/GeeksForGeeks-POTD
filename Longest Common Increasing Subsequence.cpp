class Solution {
  public:
    // vector<int> lcs(vector<int> &a, vector<int> &b){
    //     int n = a.size();
    //     int m = b.size();
    //     vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    //     for(int i=1; i<=n; i++){
    //         for(int j=1; j<=m; j++){
    //             if(a[i-1] == b[j-1])
    //                 dp[i][j] = 1+dp[i-1][j-1];
    //             else
    //                 dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    //         }
    //     }
    //     vector<int> res;
    //     int i=n, j=m;
    //     while(i>0 && j>0){
    //         if(a[i-1] == b[j-1]){
    //             res.push_back(a[i-1]);
    //             i--; j--;
    //         }
    //         else{
    //             if(dp[i][j-1] > dp[i-1][j])
    //                 j--;
    //             else
    //                 i--;
    //         }
    //     }
    //     reverse(res.begin(), res.end());
    //     return res;
    // }

    int LCIS(vector<int> &a, vector<int> &b) {
        // code here
        // vector<int> LCS = lcs(a, b);
        // int n = LCS.size();
        // if(n == 1) return 1;
        // int res = 0;
        // vector<int> dp(n, 1);
        // for(int i=1; i<n; i++){
        //     for(int j=0; j<i; j++){
        //         if(LCS[j] < LCS[i])
        //             dp[i] = max(dp[i], 1+dp[j]);
        //     }
        //     res = max(res, dp[i]);
        // }
        // return res;
        
        int n = a.size(), m = b.size();
        vector<int> dp(m);
        for (int i = 0; i < n; i++) {
            int currentMax = 0;
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    dp[j] = currentMax + 1;
                } 
                else if (b[j] < a[i]) {
                    currentMax = max(currentMax, dp[j]);
                }
            }
        }
        int ans = 0;
        for (int v : dp) 
            ans = max(ans, v);
        return ans;
    }
};