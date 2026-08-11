class Solution {
  public:
   int n;
   int m;
   bool check(int i,int j){
       return i>=0 && j>=0 && i<n && j<m;
   }
    
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries,int p) {
        // code here
        n = mat.size();
        m = mat[0].size();
        int q = queries.size();
        vector<int>temp;
        vector<vector<int>>sum(n+1,vector<int>(m+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                sum[i][j] = mat[i][j]+sum[i][j+1]+sum[i+1][j]-sum[i+1][j+1];
            }
        }
        
        for(int k=0;k<q;k++){
            
            int i = queries[k][0];
            int j = queries[k][1];
            
            int r = min({i,n-i-1,j,m-j-1});
            int l = 0;
            int ans = -1;
            
            while(l<=r){
                
                int mid = l+((r-l)/2);
                int i1 = i-mid;
                int j1 = j-mid;
                
                int count = sum[i1][j1] - ((check(i+mid+1,j1))?sum[i+mid+1][j1]:0) - ((check(i-mid,j+mid+1))?sum[i-mid][j+mid+1]:0) + ((check(i+mid+1,j+mid+1))?sum[i+mid+1][j+mid+1]:0);
                
                if(count<=p){
                    
                    ans = (2*mid)+1;
                    l = mid+1;
                }
                else r = mid-1;
                
            }
            
            temp.push_back(ans);
            
        }
        
        return temp;
        
    }
};
