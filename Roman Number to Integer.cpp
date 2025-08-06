class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int n = s.length();
        int res = mp[s[0]];
        for(int i=1; i<n; i++){
            if(mp[s[i]] > mp[s[i-1]])
                res += (mp[s[i]] - 2*mp[s[i-1]]);
            else
                res += mp[s[i]];
        }
        return res;
    }
};