class Solution{
		
	public:
	int help(int i,int j,int n,int m,int a[],int b[],int diff,vector<vector<int>> &dp){
	    if(i==n or j==m)return 0;
	    if(dp[i][j]!=-1)return dp[i][j];
	    int sum1 = 0, sum2 = 0;
	    if(diff){
	        sum1 = help(i+1,j,n,m,a,b,diff-1,dp);
	    }
	    sum2 = a[i]*b[j]+help(i+1,j+1,n,m,a,b,diff,dp);
	    return dp[i][j] = max(sum1,sum2);
	}
	
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		vector<vector<int>> dp(n,vector<int>(m,-1));
		return help(0,0,n,m,a,b,n-m,dp);
	} 
};