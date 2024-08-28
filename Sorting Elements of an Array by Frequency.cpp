class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int, int> mp;
        for(auto i : arr)
            mp[i]++;
        vector<pair<int, int>> vec;
        for(auto &it : mp)
            vec.push_back({it.second, it.first});
        
        auto comp = [&](pair<int, int> a, pair<int, int> b){
            if(a.first == b.first)
                return a.second < b.second;
            if(a.first > b.first)
                return true;
            return false;
        };
        sort(vec.begin(), vec.end(), comp);
        vector<int> res;
        for(auto it : vec){
            while(it.first--)
                res.push_back(it.second);
        }
        return res;
    }
};