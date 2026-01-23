class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> nge(n, n), pge(n,-1);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                nge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                pge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        int res = 0;
        for(int i=0; i<n; i++){
            int cur = (nge[i]-i-1) + (i-pge[i]-1) + 1;
            res = max(res, cur);
        }
        return res;
    }
};