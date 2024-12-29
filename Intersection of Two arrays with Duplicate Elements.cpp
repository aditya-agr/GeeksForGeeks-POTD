class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int> mp;
        for(int x : a)
            mp[x]++;
        vector<int> res;
        for(int x : b){
            if(mp[x]){
                res.push_back(x);
                mp[x] = 0;
            }
        }
        return res;
    }
};