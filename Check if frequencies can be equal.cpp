class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        vector<int> f(26);
        unordered_map<int, int> mp;
        for(char c : s)
            f[c-'a']++;
        for(int i=0; i<26; i++)
            if(f[i]!=0) mp[f[i]]++;
        if(mp.size() == 2){
            if(mp.find(1) != mp.end() && mp[1] == 1)
                return true;
            int mxv = 0, mxk = 0;
            for(auto it : mp){
                if(mxk < it.first){
                    mxv = it.second;
                    mxk = it.first;
                }
            }  
            if(mxv ==  1){
                mp.erase(mxk);
            }
            mp[mxk-1]++;
            
        }
        return mp.size() == 1;
    }
};