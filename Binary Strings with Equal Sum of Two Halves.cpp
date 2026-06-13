class Solution {
  public:
    long long power(int a, int b){
        if(b==0)
            return 1;
        long long mod = 1e9+7;
        long long half = power(a, b/2);
        long long res = (half*half)%mod;
        if(b%2)
            res = (res*a)%mod;
        return res%mod;
    }
    int computeValue(int n) {
        // code here
        long long mod = 1e9+7;
        long long res = 2;
        long long num = n, deno = 1;
        for(int i=1; i<n; i++){
            long long ideno = power(deno,mod-2)%mod;
            long long ans = (num*ideno)%mod;
            res = (res%mod+(ans*ans)%mod)%mod;
            num = (num*(n-i))%mod;
            deno = (deno*(i+1))%mod;
        }
        return res;
    }
};