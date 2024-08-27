class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        vector<int> l(n), r(n);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top()>=arr[i])
                st.pop();
            if(!st.empty())
                l[i] = st.top();
            st.push(arr[i]);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top()>=arr[i])
                st.pop();
            if(!st.empty())
                r[i] = st.top();
            st.push(arr[i]);
        }
        int mx=INT_MIN;
        for(int i=0; i<n; i++)
            mx = max(mx, abs(l[i]-r[i]));
        return mx;
    }
};