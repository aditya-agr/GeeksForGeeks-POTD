class Solution {
  public:
    void solve(int i, string &s, unordered_set<string> &res){
        int n = s.length();
        if(i==n){
            res.insert(s);
            return;
        }
        for(int j=i; j<n; j++){
            swap(s[i], s[j]);
            solve(i+1, s, res);
            swap(s[i], s[j]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        unordered_set<string> res;
        solve(0, s, res);
        vector<string> ans(res.begin(), res.end());
        return ans; 
    }
};