class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        vector<int> f(26);
        for(char c : s)
            f[c-'a']++;
        unordered_map<int, int> mp;
        int mx = 0;
        for(int i=0; i<26; i++){
            mx = max(mx, f[i]);
            if(f[i]!=0) mp[f[i]]++;
        }
        while(k>0 && mp[mx]>0){
            int rem = min(k, mp[mx]);
            mp[mx] -= rem;
            k -= rem;
            mp[mx-1] += rem;
            if(mp[mx] == 0)
                mp.erase(mx);
            mx--;
        }
        int val = 0;
        for(auto it : mp)
            val += it.first*it.first*it.second;
        return val;
    }
};