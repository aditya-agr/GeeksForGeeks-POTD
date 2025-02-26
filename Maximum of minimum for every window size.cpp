class Solution {
  public:
    vector<int> nextSmallerElement(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> res(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(st.empty())
                res[i] = n;
            else
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> prevSmallerElement(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> res(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(st.empty())
                res[i] = -1;
            else
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        vector<int> ns = nextSmallerElement(arr);
        vector<int> ps = prevSmallerElement(arr);
        int n = arr.size();
        vector<int> res(n);
        for(int i=0; i<n; i++){
            int l = ns[i] - ps[i] - 1;
            res[l-1] = max(res[l-1], arr[i]);
        }
        for(int i=n-2; i>=0; i--){
            res[i] = max(res[i], res[i+1]);
        }
        return res;
    }
};