
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        unordered_map<int,vector<int>> mp;
        int n = arr.size();
        for(int i=0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        vector<vector<int>> res;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int curr = 0-(arr[i]+arr[j]);
                if(mp.find(curr) != mp.end()){
                    int m = mp[curr].size();
                    for(int k=m-1; k>=0; k--){
                        if(mp[curr][k] <= j) break;
                        else res.push_back({i, j, mp[curr][k]});
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};