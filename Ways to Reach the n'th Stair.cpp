class Solution {
  public:
    int countWays(int n) {
        // your code here
        if(n<=1)
            return 1;
        int a=1, b=1, c;
        for(int i=2; i<=n; i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
        // return countWays(n-1) + countWays(n-2);
    }
};