class Solution {
  public:
    int minOperation(int n) {
        // code here
        int res = 0;
        while(n){
            if(n%2)
                n -= 1;
            else
                n /= 2;
            res++;
        }
        return res;
    }
};