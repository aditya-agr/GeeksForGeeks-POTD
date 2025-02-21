class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char> st;
        for(char c : s){
            if(c == '[' || c == '{' || c == '(')
                st.push(c);
            else{
                char t = (st.empty()) ? '#' : st.top();
                if(c == ']' && t == '[')
                    st.pop();
                else if(c == '}' && t == '{')
                    st.pop();
                else if(c == ')' && t == '(')
                    st.pop();
                else 
                    return false;
            }
        }
        return st.empty();
    }
};