class Solution {
  public:
    int maxLength(string& s) {
        // code here
        stack<int> st;
        st.push(-1);
        int n = s.length();
        int res = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(')
                st.push(i);
            else{
                st.pop();
                if(!st.empty())
                    res = max(res, i-st.top());
                else
                    st.push(i);
            }
        }
        return res;
    }
};