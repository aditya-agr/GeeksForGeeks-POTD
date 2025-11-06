class Solution {
  public:
    int numberOfWays(int n) {
        // code here
        if(n == 1 || n == 2 || n == 3)
            return n;
        int a = 2, b = 3;
        int c = 0;
        for(int i=0; i<n-3; i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};