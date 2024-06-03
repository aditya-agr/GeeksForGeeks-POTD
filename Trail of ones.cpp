class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        // code here
        int a=0, b=1, c;
        int ans=1, m=1e9+7;
        if(n==2)
            return 1;
        for(int i=3; i<=n; i++){
            c = (a + b)%m;
            ans = ((ans*2)%m + c%m)%m;
            a = b;
            b = c;
        }
        return ans;
    }
};