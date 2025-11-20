class Solution {
  public:
    unordered_map<char, int> mincost(char u, unordered_map<char, vector<pair<char, int>>> &adj){
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        unordered_map<char, int> mp;
        pq.push({0, u});
        mp[u] = 0;
        while(!pq.empty()){
            int c = pq.top().first;
            char x = pq.top().second;
            pq.pop();
            for(auto it : adj[x]){
                char y = it.first;
                int w = it.second;
                if(!mp.count(y) || c+w < mp[y]){
                    mp[y] = c+w;
                    pq.push({c+w, y});
                }
            }
        }
        return mp;
    }
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        // code here
        // unordered_map<char, vector<pair<char, int>>> adj;
        // int n = transform.size();
        // for(int i=0; i<n; i++){
        //     char u = transform[i][0];
        //     char v = transform[i][1];
        //     if(u == v) continue;
        //     int c = cost[i];
        //     adj[u].push_back({v, c});
        // }
        // int m = s.length();
        // int res = 0;
        // vector<unordered_map<char, int>> dp(26);
        // for(int i=0; i<26; i++){
        //     dp[i] = mincost('a'+i, adj);
        // }
        // for(int i=0; i<m; i++){
        //     if(s[i]!=t[i]){
        //         unordered_map<char, int> st = dp[s[i]-'a'];
        //         unordered_map<char, int> ts = dp[t[i]-'a'];
        //         int mn = INT_MAX;
        //         for(auto it : st){
        //             char x = it.first;
        //             if(ts.count(x))
        //                 mn = min(mn, ts[x]+st[x]);
        //         }
        //         if(mn == INT_MAX)
        //             return -1;
        //         res += mn;
        //     }
        // }
        // return res;
        
        vector<vector<int>> adj(26, vector<int>(26, INT_MAX));
        int n = transform.size();
        for(int i=0; i<n; i++){
            int u = transform[i][0]-'a';
            int v = transform[i][1]-'a';
            if(u == v) continue;
            int c = cost[i];
            adj[u][v] = min(adj[u][v], c);
        }
        for(int i=0; i<26; i++)
            adj[i][i] = 0;
        for(int k=0; k<26; k++)
            for(int i=0; i<26; i++)
                for(int j=0; j<26; j++)
                    if(adj[i][k]<INT_MAX && adj[k][j]<INT_MAX)
                        adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
        
        int m = s.length();
        int res = 0;
        for(int i=0; i<m; i++){
            if(s[i]!=t[i]){
                int a = s[i]-'a';
                int b = t[i]-'a';
                int mn = INT_MAX;
                for(int c=0; c<26; c++){
                    if(adj[a][c]<INT_MAX && adj[b][c]<INT_MAX)
                        mn = min(mn, adj[a][c]+adj[b][c]);
                }
                if(mn == INT_MAX)
                    return -1;
                res += mn;
            }
        }
        return res;
        
    }
};