class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        // code here
        int ans=1, min=INT_MAX;
        for(int i=0; i<n; i++){
            int one=0;
            for(int j=0; j<m; j++){
                if(a[i][j])
                    one++;
            }
            if(min>one){
                min = one;
                ans = i+1;
            }
        }
        return ans;
    }
};
