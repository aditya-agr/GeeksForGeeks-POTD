class Solution {
  public:
    int MAX = 10001;
    
    int cntCoprime(vector<int>& arr) {
        // code here
        int n = arr.size();
        int freq[MAX];
        memset(freq, 0, sizeof(freq));
        for(int x : arr)
            freq[x]++;
        
        int cnt[MAX];
        memset(cnt, 0, sizeof(cnt));
        for(int i=1; i<MAX; i++){
            for(int j=i; j<MAX; j+=i)
                cnt[i] += freq[j];
        }
        
        vector<int> mobius = getmobius(MAX);
        long long res = 0;
        for(int i=1; i<MAX; i++){
            if(cnt[i]>1){
                long long pairs = (1LL*cnt[i]*(cnt[i]-1))/2;
                res += (1LL*mobius[i]*pairs);
            }
        }
        return res;
    }
    
    vector<int> getmobius(int n){
        vector<int> mobius(n, 1);
        vector<bool> isPrime(n, true);
        
        for(int i=2; i<n; i++){
            if(isPrime[i]){
                for(int j=i; j<n; j+=i){
                    isPrime[j] = false;
                    mobius[j] *= -1;
                }
                for(long long j=i*i; j<n; j+=i*i)
                    mobius[j] = 0;
            }
        }
        return mobius;
    }
};
