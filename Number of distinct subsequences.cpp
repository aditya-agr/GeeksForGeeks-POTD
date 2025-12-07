class Solution {
  public:
    int distinctSubseq(string &s) {
        // code here
        int n = s.size();
	    int mod =1e9+7;
	    vector<int>dp(n+1);
	    vector<int>pos(26,-1);
	    dp[0]=1;
	    for(int i=0; i<n; i++){
	        dp[i+1] = (dp[i]*2)%mod;
	        if(pos[s[i]-'a']!=-1)
	            dp[i+1] = (dp[i+1] - dp[pos[s[i]-'a']-1] + mod)%mod;
	        pos[s[i]-'a'] = i+1;
	    }
	    return dp[n];
    }
};