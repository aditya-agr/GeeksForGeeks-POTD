class Solution {
  public:
    void solve(int n, int k, vector<int> &cur, vector<vector<int>> &res, int i){
        if(n==0 && k==0){
            res.push_back(cur);
            return;
        }
        if(n<=0 || k<=0)
            return;
        for(int j=i; j<=9; j++){
            cur.push_back(j);
            solve(n-j, k-1, cur, res, j+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<int> cur;
        vector<vector<int>> res;
        solve(n, k, cur, res, 1);
        return res;
    }
};