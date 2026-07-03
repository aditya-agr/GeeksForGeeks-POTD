class Solution {
  public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> pre(n+1, vector<int>(m+1));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1])
                    pre[i][j] = pre[i-1][j-1] + 1;
                else
                    pre[i][j] = max(pre[i-1][j], pre[i][j-1]);
            }
        }
        
        int lcs1 = pre[n][m];
        
        unordered_set<char> st(s2.begin(), s2.end());
        
        vector<vector<int>> suf(n+1, vector<int>(m+1));
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(s1[i] == s2[j])
                    suf[i][j] = suf[i+1][j+1] + 1;
                else
                    suf[i][j] = max(suf[i+1][j], suf[i][j+1]);
            }
        }
        
        int cnt = 0;
        for(int i=0; i<=n; i++){
            for(int j=0; j<26; j++){
                char c = 'a'+j;
                if(!st.count(c))
                    continue;
                bool ok = false;
                for(int k=0; k<m && !ok; k++){
                    if(s2[k] != c)
                        continue;
                    if(pre[i][k] + 1 + suf[i][k+1] == lcs1+1)
                        ok = true;
                }    
                if(ok)
                    cnt++;
            }
        }
        return cnt;
        
    }
};
