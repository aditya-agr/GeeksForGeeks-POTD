class Solution {
  public:
    int minimumStep(int n) {
        // code here
        int res = 0;
        if(n == 2 || n == 1)
            return n-1;
        while(n > 2){
            if(n%3 == 0){
                res += 1;
                n = n/3;
            }
            else{
                res += n%3;
                n -= n%3;
            }
        }
        if(n == 2)
            res++;
        return res;
    }
};