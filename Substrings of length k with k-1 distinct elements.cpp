class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        vector<int> f(26);
        int i=0, j=0, dist=0;
        int n = s.length();
        int res = 0;
        while(j<n){
            if(f[s[j]-'a'] == 0)
                dist++;
            f[s[j]-'a']++;
            if(j-i+1 > k){
                f[s[i]-'a']--;
                if(f[s[i]-'a'] == 0)
                    dist--;
                i++;
            }
            if(j-i+1 == k && dist == k-1)
                res++;
            j++;
        }
        return res;
    }
};