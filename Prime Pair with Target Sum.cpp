class Solution {
  public:
    vector<int> getPrimes(int n) {
        // code here
        bool prime[n + 1];
        prime[0] = false;
        prime[1] = false;
        memset(prime, true, sizeof(prime));
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        for(int i=2; i<n; i++)
            if(prime[i] && prime[n-i])
                return {i,n-i};
        return {-1,-1};
    }
};