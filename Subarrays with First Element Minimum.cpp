class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(!st.empty())
                nse[i] = st.top();
            st.push(i);
        }
        int res = 0;
        for(int i=0; i<n; i++)
            res += nse[i]-i;
        return res;
        
    }
};