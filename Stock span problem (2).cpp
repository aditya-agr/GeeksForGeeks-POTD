class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        stack<int> st;
        int n = arr.size();
        vector<int> res(n, -1);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0; i<n; i++){
            res[i] = i-res[i];
        }
        return res;
    }
};