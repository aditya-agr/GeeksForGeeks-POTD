class Solution {
  public:
    int minSquares(int n, int m) {
        // code here
        int res = 0;
        while(n && m){
            int mn = min(n, m);
            int mx = max(n, m);
            int d = mx/mn;
            res += d;
            mx -= d*mn;
            n = mx;
            m = mn;
        }
        return res;
    }
};