class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        int n = s.length();
        stack<char> st;
        int i=0;
        for(int i=0; i<n; i++){
            if(s[i] == ')'){
                int count = 0;
                while(!st.empty() && st.top() != '('){
                    st.pop();
                    count++;
                }
                if(count <= 1)
                    return true;
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(s[i]);
        }
        return false;
    }
};
