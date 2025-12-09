class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        unordered_set<int> st;
        vector<int> res;
        for(int x : arr){
            if(st.count(x))
                res.push_back(x);
            else
                st.insert(x);
        }
        return res;
    }
};