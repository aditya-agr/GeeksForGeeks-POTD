class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        // int n = arr.size();
        // vector<pair<int, int>> res;
        // for(int i=0 ; i<n; i++)
        //     res.push_back({abs(arr[i]-x), i});
        // sort(res.begin(), res.end());
        // vector<int> ans(n);
        // for(int i=0; i<n; i++)
        //     ans[i] = arr[res[i].second];
        // arr = ans;
        
        auto comp = [&](int a, int b){
            return abs(a-x) < abs(b-x);
        };
        stable_sort(arr.begin(), arr.end(), comp);
    }
};