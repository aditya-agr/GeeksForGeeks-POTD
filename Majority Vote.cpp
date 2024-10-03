class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> res;
        for(int x : nums)
            mp[x]++;
        for(auto it : mp){
            if(it.second > n/3)
                res.push_back(it.first);
        }
        sort(res.begin(), res.end());
        if(res.empty())
            res.push_back(-1);
        return res;
    }
};