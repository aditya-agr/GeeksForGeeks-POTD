class Solution {
  public:
    int find(vector<int> &a){
        int n = a.size();
        stack<int> st;
        int res = 0;
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || a[st.top()]>a[i])){
                int ele = a[st.top()]; 
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                res = max(res, ele*(nse-pse-1));
            }
            st.push(i);
        }
        return res;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int res = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dp[i][j] = mat[i][j];
                if(i>0 && mat[i][j]){
                    dp[i][j] += dp[i-1][j]; 
                }
            }
            int mx = find(dp[i]);
            res = max(res, mx);
        }
        return res;
    }
};