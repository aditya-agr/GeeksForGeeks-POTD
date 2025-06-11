class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<pair<int, int>> st;
        int n = color.size();
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push({color[i], radius[i]});
                continue;
            }
            pair<int, int> tp = st.top();
            if(tp.first == color[i] && tp.second == radius[i])
                st.pop();
            else
                st.push({color[i], radius[i]});
        }
        return st.size();
    }
};