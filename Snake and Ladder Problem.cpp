class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        // code here
        unordered_map<int, int> l, s;
        int m = lad.size();
        for(int i=0; i<m; i+=2){
            l[lad[i]] = lad[i+1];
        }
        
        int o = sn.size();
        for(int i=0; i<o; i+=2)
            s[sn[i]] = sn[i+1];
            
        
        vector<int> dp(n*n+1, INT_MAX);
        queue<int> q;
        q.push(1);
        dp[1] = 0;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(u == n*n)
                return dp[n*n];
            for(int i=1; i<=6; i++){
                int v = u+i;
                if(v > n*n)
                    break;
                if(l.count(v))
                    v = l[v];
                else if(s.count(v))
                    v = s[v];
                if(dp[v] > dp[u]+1){
                    dp[v] = dp[u]+1;
                    q.push(v);
                }
            }
        }
        return dp[n*n] == INT_MAX ? -1 : dp[n*n];
    }
};