class Solution {
  public:
    void solve(string res, int n, vector<string> &ans){
        if(n == 0){
            ans.push_back(res);
            return ;
        }
        solve(res+"0", n-1, ans);
        solve(res+"1", n-1, ans);
    }
    vector<string> binstr(int n) {
        // code here
        string res = "";
        vector<string> ans;
        solve(res, n, ans);
        return ans;
    }
};