class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> nsel(n), nser(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            nsel[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) 
            st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nser[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        int res = 0;
        for(int i=0; i<n; i++)
            res += (nser[i]-i)*(i-nsel[i])*arr[i];
        return res;
    }
};