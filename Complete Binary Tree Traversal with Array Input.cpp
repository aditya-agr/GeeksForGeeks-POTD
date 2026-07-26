class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> res;
        int it = 1, i = 0;
        while(i<n){
            vector<int> cur;
            for(int j=i; j<i+it && j<n; j++){
                cur.push_back(arr[j]);
            }
            i += it;
            it *= 2;
            sort(cur.begin(), cur.end());
            res.push_back(cur);
        }
        return res;
    }
};
