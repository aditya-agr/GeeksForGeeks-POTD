class Solution {
  public:
    vector<int> findPairs(vector<int>& arr) {
        // code here
        unordered_map<int, pair<int, int>> mp;
        int n = arr.size();
        vector<int> ans = {-1, -1, -1, -1};
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum = arr[i]+arr[j];
                if(mp.count(sum)){
                    int x = mp[sum].first;
                    int y = mp[sum].second;
                    if (x != i && x != j && y != i && y != j) {
                        vector<int> curr = {x, y, i, j};
                        if (ans[0] == -1 || curr < ans) {
                            ans = curr;
                        }
                    }
                }
                else
                    mp[sum] = {i, j};
            }
        }
        return ans;
    }
};