class Solution {
  public:
    int beautySum(string &s) {
        // code here
        int res = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            vector<int> f(26);
            for(int j=i; j<n; j++){
                f[s[j]-'a']++;
                int mx=0, mn=INT_MAX;
                for(int k=0; k<26; k++){
                    if(f[k] != 0){
                        mx = max(f[k], mx);
                        mn = min(f[k], mn);
                    }
                }
                res += mx-mn;
            }
        }
        return res;
    }
};