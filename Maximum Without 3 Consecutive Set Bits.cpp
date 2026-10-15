class Solution {
  public:
    int maxValue(int n) {
        // code here
        int cnt = 0;
        for(int i=32; i>=0; i--){
            if(n&(1<<i))
                cnt += 1;
            else
                cnt = 0;
            
            if(cnt == 3){
                cnt = 0;
                n = n^(1<<i);
            }
        }
        return n;
    }
};