class Solution {
  public:
    long long findNth(long long n) {
        // code here.
        long long res=0, mul=1;
        while(n){
            int rem = n%9;
            res += mul*rem;
            mul *= 10;
            n /= 9;
        }
        return res;
    }
};