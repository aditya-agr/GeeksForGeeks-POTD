
class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
    
        for(int i=0; i<2*n; i++){
            int idx = i%n;
            while(!st.empty() && arr[st.top()] < arr[idx]){
                res[st.top()] = arr[idx];
                st.pop();
            }
            st.push(idx);
        }
        return res;
    }
};