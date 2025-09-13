class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        int i=0, j=0;
        int hs=1, vs=1;
        int res = 0;
        while(i<m-1 && j<n-1){
            if(x[i] >= y[j]){
                res += x[i]*hs;
                i++;
                vs++;
            }
            else{
                res += y[j]*vs;
                j++;
                hs++;
            }
        }
        while(i<m-1){
            res += x[i]*hs;
            i++;
            vs++;
        }
        while(j<n-1){
            res += y[j]*vs;
            j++;
            hs++;
        }
        return res;
    }
};
