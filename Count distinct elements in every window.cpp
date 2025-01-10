class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<int> res;
        for(int i=0; i<k; i++)
            mp[arr[i]]++;
        res.push_back(mp.size()); 
        for(int i=k; i<n; i++){
            mp[arr[i]]++;
            mp[arr[i-k]]--;
            if(mp[arr[i-k]] == 0)
                mp.erase(arr[i-k]);
            res.push_back(mp.size());
        }
        return res;
    }
};