class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n = arr.size();
        int mx = 0;
        stack<int> st;
        vector<int> res(n);
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || arr[st.top()] > arr[i])){
                int ele = arr[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                int idx = nse-pse-1;
                if(idx > n) res[n-1] = max(res[n-1], ele);
                else    res[idx-1] = max(res[idx-1], ele);
            }
            st.push(i);
        }
        for(int i=n-2; i>=0; i--)
                res[i] = max(res[i],res[i+1]);
        
        return res;
    }
};