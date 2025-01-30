class Solution {
  public:
    vector<bool> col, rdiag, ldiag;
    vector<vector<int>> res;
    int N;
    void solve(int row, vector<int> &ans){
        if(row==N){
            res.push_back(ans);
            return;
        }
        for(int i=0; i<N; i++){
            if(!col[i] && !ldiag[i-row+N-1] && !rdiag[i+row]){
                col[i] = true;
                ldiag[i-row+N-1] = true;
                rdiag[i+row] = true;
                ans.push_back(i+1);
                solve(row+1, ans);
                ans.pop_back();
                rdiag[i+row] = false;
                ldiag[i-row+N-1] = false;
                col[i] = false;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        col.resize(n, false);
        ldiag.resize(2*n-1, false);
        rdiag.resize(2*n-1, false);
        N = n;
        vector<int> ans;
        solve(0, ans);
        return res;
    }
};