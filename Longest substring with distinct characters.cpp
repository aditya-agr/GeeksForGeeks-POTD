class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        vector<int> idx(26);
        int i=0, j=0, n=s.length();
        int res = 1;
        while(j<n){
            idx[s[j]-'a']++;
            while(idx[s[j]-'a'] > 1){
                idx[s[i]-'a']--;
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};