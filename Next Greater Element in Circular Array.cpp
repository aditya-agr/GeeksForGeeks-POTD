class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        stack<int> st;
        int n = arr.size();
        vector<int> res(n, -1);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                res[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                res[st.top()] = arr[i];
                st.pop();
            }
        }
        return res;
    }
};