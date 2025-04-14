class Solution {
  public:
    bool dfs(int u, vector<vector<int>> &adj, vector<int> &vis,
    vector<int> &recur, string &ans){
        vis[u] = 1;
        recur[u] = 1;
        for(int v : adj[u]){
            if(!vis[v]){
                if(!dfs(v, adj, vis, recur, ans))
                    return false;
            }
            else if(recur[v])
                return false;
        }
        ans += (u+'a');
        recur[u] = 0;
        return true;
        
    }
    string findOrder(vector<string> &words) {
        // code here
        vector<vector<int>> adj(26);
        vector<int> exist(26);
        vector<int> vis(26);
        vector<int> recur(26);
        
        for(string s : words)
            for(char c : s)
                exist[c-'a'] = 1;
        
        int n = words.size();
        string ans = "";
        for(int i=0; i<n-1; i++){
            string a = words[i];
            string b = words[i+1];
            int N = a.size(), M = b.size();
            int idx = 0;
            while(idx<N && idx<M && a[idx]==b[idx])
                idx++;
            if(idx<N && idx==M) return "";
            if(idx<N && idx<M){
                adj[a[idx]-'a'].push_back(b[idx]-'a');
            }
        }
        for(int i=0; i<26; i++){
            if(exist[i] && !vis[i]){
                if(!dfs(i, adj, vis, recur, ans))
                    return "";
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};