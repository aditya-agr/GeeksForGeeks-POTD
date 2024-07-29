class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int res=-1, mx=0;
        int n = arr.size();
        int m = arr[0].size();
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<m; j++){
                if(arr[i][j])
                    cnt++;
            }
            if(cnt>mx){
                mx = cnt;
                res = i;
            }
        }
        return res;
    }
};