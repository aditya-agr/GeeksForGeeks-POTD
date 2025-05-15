class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        vector<int> mp(26);
        int res = s.length();
        for(char c : s){
            res += mp[c-'a'];
            mp[c-'a']++;
        }
        return res;
    }
};