class Solution {
  public:
    int solve(vector<int>&a,vector<int>&b,int i,int j, vector<vector<int>>& dp){
        int n = a.size() , m = b.size();
        
        // Initially I solved with 3 dp state but then I realised that k can be derieved from i,j
        int k = n - i - m + j;
        
        if(i >= n || j >= m || k < 0)return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(k == 0){
            int ans = 0;
            for(;j<m && i<n;i++){
                ans += a[i] * b[j];
                j++;
            }
            return dp[i][j] = ans;
        }
        
        // take i
        int t1 = a[i] * b[j] + solve(a,b,i+1,j+1,dp);
        
        // leave i
        int t2 = solve(a,b,i+1,j,dp);
        
        return dp[i][j] = max(t1,t2);
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size();int m = b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(a,b,0,0,dp);
    }
};