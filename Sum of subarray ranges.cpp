class Solution {
  public:
    int subarrayRanges(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> nge(n,n), nse(n,n), pge(n,-1), pse(n,-1);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                nge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                nse[st.top()] = i;
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
        while(!st.empty())
            st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        int res = 0;
        for(int i=0; i<n; i++){
            res -= arr[i]*((nse[i]-i)*(i-pse[i]));
            res += arr[i]*((nge[i]-i)*(i-pge[i]));
        }
        return res;
    }
};