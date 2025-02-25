class Solution {
  public:
    vector<int> nextSmallestElement(vector<int> & arr){
        stack<int> st;
        int n = arr.size();
        vector<int> res(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            if(st.empty())
                res[i] = n;
            else
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> prevSmallestElement(vector<int> & arr){
        stack<int> st;
        int n = arr.size();
        vector<int> res(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            if(st.empty())
                res[i] = -1;
            else
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    int getMaxArea(vector<int> &arr) {
        // Your code here
        vector<int> ns = nextSmallestElement(arr);
        vector<int> ps = prevSmallestElement(arr);
        int res = 0;
        int n = arr.size();
        for(int i=0; i<n; i++)
            res = max(res, (ns[i]-ps[i]-1)*arr[i]);
        return res;
    }
};