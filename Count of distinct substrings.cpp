class Solution {
  public:
    int countSubs(string& s) {
        // code here
        unordered_set<int, int> st;
        for(int i=0; i<n; i++){
            string curr = "";
            for(int j=i; j<n; j++){
                curr += s[j];
                st.insert(curr);
            }
        }
        return st.size();
    }
};