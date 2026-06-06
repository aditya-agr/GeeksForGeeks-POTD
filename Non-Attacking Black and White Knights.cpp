class Solution {
  public:
    vector<vector<int>> dir = {{-2,-1}, {-2,1}, {2,-1}, {2,1}, {1,2}, {-1,2}, {1,-2}, {-1,-2}};
    int numOfWays(int n, int m) {
        // code here
        long long res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                long long cur = n*m-1;
                for(vector<int> &d : dir){
                    int i_ = i+d[0];
                    int j_ = j+d[1];
                    if(i_>=0 && i_<n && j_>=0 && j_<m)
                        cur--;
                }
                res += cur;
            }
        }
        return res;
    }
};