class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        vector<int> f(26);
        int distinct = 0;
        int i=0, j=0;
        int res = -1;
        int n = s.length();
        while(j<n){
            if(f[s[j]-'a'] == 0)
                distinct++;
            f[s[j]-'a']++;
            while(distinct > k){
                f[s[i]-'a']--;
                if(f[s[i]-'a'] == 0)
                    distinct--;
                i++;
            }
            if(distinct == k)
                res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};