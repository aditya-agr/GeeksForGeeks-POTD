class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        if(r > n)
            return 0;
        long long res = 1;
        int curr = 1;
        for(int i=0; i<r; i++){
            res *= (n-i);
            res /= (i+1);
        }
        return res;
    }
};
