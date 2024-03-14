class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        // code here
        int row[n][n], col[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a[i][j]=='X')
                    row[i][j] = (j!=0) ? row[i][j-1] + 1 : 1;
                else
                    row[i][j]=0;
                if(a[j][i]=='X')
                    col[j][i] = (j!=0) ? col[j-1][i] + 1 : 1;
                else
                    col[j][i]=0;
            }
        }
        int maxi=0;
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                int size = min(row[i][j], col[i][j]);
                    // cout<<size<<maxi;
                while(size>maxi){
                    if(row[i-size+1][j]>=size && col[i][j-size+1]>=size){
                        maxi = size;
                        break;
                    }
                    else
                        size--;
                }
            }
        }
        return maxi;
    }
};