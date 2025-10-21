class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        unordered_map<int, int> f;
        for(int x : arr)
            f[x]++;
        vector<pair<int, int>> vec;
        for(auto it : f)
            vec.push_back({it.second, it.first});
        
        sort(vec.rbegin(), vec.rend());
        vector<int> res;
        for(int i=0; i<k; i++)
            res.push_back(vec[i].second);
        return res;
    }
};
ss