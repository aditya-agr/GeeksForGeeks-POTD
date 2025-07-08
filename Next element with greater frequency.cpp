class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int> f;
        for(int &x : arr)
            f[x]++;
        
        stack<int> st;
        vector<int> res(n, -1);
        for(int i=0; i<n; i++){
            while(!st.empty() && f[arr[st.top()]] < f[arr[i]]){
                res[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
