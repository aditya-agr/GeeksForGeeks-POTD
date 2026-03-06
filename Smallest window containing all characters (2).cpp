class Solution {
  public:
    bool check(vector<int> &fs, vector<int> &fp){
        for(int i=0; i<26; i++){
            if(fs[i] < fp[i])
                return false;
        }
        return true;
    }
    string minWindow(string &s, string &p) {
        // code here
        vector<int> fs(26), fp(26);
        for(char c : p)
            fp[c-'a']++;
            
        int n = s.length();
        int i=0, j=0;
        int mnidx=-1, mn=INT_MAX;
        while(j<n){
            fs[s[j]-'a']++;
            while(check(fs, fp)){
                int cur = j-i+1;
                if(cur < mn){
                    mn = cur;
                    mnidx = i;
                }
                fs[s[i]-'a']--;
                i++;
            }
            j++;
        }
        if(mn == INT_MAX)
            return "";
        return s.substr(mnidx, mn);
    }
};