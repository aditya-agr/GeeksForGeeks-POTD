class Solution {
  public:
    int countStrings(string &s) {
        // code here
        vector<int> mp(26);
        int n = s.length();
        int res = 0;
        for(int i=0; i<n; i++){
            res += i - mp[s[i]-'a'];
            mp[s[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(mp[s[i]-'a'] > 1){
                res++;
                break;
            }
        }
        return res;
    }
};
