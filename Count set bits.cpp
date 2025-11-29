class Solution {
  public:
    int countSetBits(int n) {
        // code here
        int nxt = 2, cur = 1;
        int res = 0;
        while(cur <= n){
            int blocks = (n+1)/nxt;
            res += blocks*cur;
            int rem  = (n+1)%nxt;
            res += max(0, rem-cur);
            cur = nxt;
            nxt *= 2;
        }
        return res;
    }
};
