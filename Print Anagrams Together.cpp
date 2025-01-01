class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        unordered_map<string, int> mp;
        vector<vector<string>> res;
        for(string s : arr){
            string t = s;
            sort(t.begin(), t.end());
            if(mp.find(t) != mp.end()){
                int idx = mp[t];
                res[idx].push_back(s);
            }
            else{
                mp[t] = res.size();
                res.push_back({s});
            }
        }
        return res;
    }
};