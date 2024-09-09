class Solution{

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.size();
	    int m = str2.size();
	    vector<vector<int>> dp(n+1, vector<int>(m+1));
	    
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=m; j++){
	            if(str1[i-1] == str2[j-1])
	                dp[i][j] = 1+dp[i-1][j-1];
	            else
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	        }
	    }
	    int len = dp[n][m];
	    return (n-len+m-len);
	} 
};