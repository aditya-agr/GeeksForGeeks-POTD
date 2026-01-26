class Solution {
  public:
    vector<vector<int>> res;
    vector<int> cur;
    int n;
    void solve(vector<int> &arr, vector<int> &vis){
        if(cur.size() == n){
            res.push_back(cur);
            return;
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                vis[i] = 1;
                cur.push_back(arr[i]);
                solve(arr, vis);
                cur.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        n = arr.size();
        vector<int> vis(n);
        solve(arr, vis);
        return res;
    }
};