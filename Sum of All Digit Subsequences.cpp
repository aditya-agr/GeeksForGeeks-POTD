class Solution {
  public:
    int subsequenceSum(string &s) {
        // code here
        long long res = 0;
        long long n = s.length();
        long long mod = 1e9+7, prev = 0;
        for(int i=0; i<n; i++){
            int num = (s[i]-'0');
            res += res + (prev+1)*num;
            prev += prev+1;
            res %= mod;
            prev %= mod;
        }
        return res;
    }
};