class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        vector<vector<int>> dir = {{0,1}, {-1,0}, {1,0}, {0,-1}};
        dp[0][0] = 0;
        while(!pq.empty()){
            int w = pq.top()[0];
            int i = pq.top()[1];       
            int j = pq.top()[2];  
            pq.pop();
            for(vector<int> d : dir){
                int i_ = i+d[0];
                int j_ = j+d[1];
                if(i_<0 || i_>=n || j_<0 || j_>=m)
                    continue;
                int cw = abs(mat[i_][j_] - mat[i][j]);
                int mx = max(w, cw);
                if(mx < dp[i_][j_]){
                    dp[i_][j_] = mx;
                    pq.push({mx, i_, j_});
                }
            }
        }
        return dp[n-1][m-1];
        
    }
};
