class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> mp;
        int n = arr.size();
        int dist = 0;
        for(int i=0; i<k; i++){
            mp[arr[i]]++;
            if(mp[arr[i]] == 1)
                dist++;
        }
        vector<int> res;
        res.push_back(dist);
        for(int i=k; i<n; i++){
            mp[arr[i]]++;
            if(mp[arr[i]] == 1)
                dist++;
            mp[arr[i-k]]--;
            if(mp[arr[i-k]] == 0)
                dist--;
            res.push_back(dist);
        }
        return res;
        
        
    }
};