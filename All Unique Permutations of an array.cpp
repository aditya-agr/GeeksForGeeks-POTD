class Solution {
  public:
    set<vector<int>> res;
    void solve(vector<int> &arr, int i){
        if(i == arr.size()){
            res.insert(arr);
            return;
        }
        for(int j=i; j<arr.size(); j++){
            swap(arr[i], arr[j]);
            solve(arr, i+1);
            swap(arr[i], arr[j]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        solve(arr, 0);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
        
    }
};