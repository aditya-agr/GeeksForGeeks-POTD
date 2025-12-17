class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        res.push_back(arr[0]);
        int n = arr.size();
        for(int i=1; i<n; i++){
            if(res.back()[1] >= arr[i][0]){
                res.back()[1] = max(res.back()[1], arr[i][1]);
            }
            else{
                res.push_back(arr[i]);
            }
        }
        return res;
    }
};