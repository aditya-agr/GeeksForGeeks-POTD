class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> st;
        for(int x : a)
            st.insert(x);
        for(int x : b)
            st.insert(x);
        return st.size();
    }
};