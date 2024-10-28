class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        set<int> st;
        vector<int> res;
        for(int x : arr){
            if(!st.count(x))
                res.push_back(x);
            st.insert(x);
        }
        return res;
    }
};