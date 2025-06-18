class Solution {
  public:
    bool check(string &s){
        int n = s.size();
        for(int i=0; i<n/2; i++)
            if(s[i] != s[n-i-1])
                return false;
        return true;
    }
    void solve(string &s, int idx, vector<string> &cur, vector<vector<string>>&res){
        int n = s.length();
        if(idx>=n){
            res.push_back(cur);
            return;
        }
        for(int i=1; i<=n-idx; i++){
            string str = s.substr(idx, i);
            if(check(str)){
                cur.push_back(str);
                solve(s, idx+i, cur, res);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> palinParts(string &s) {
        // code here
        vector<vector<string>> res;
        vector<string> cur;
        solve(s, 0, cur, res);
        return res;
    }
};