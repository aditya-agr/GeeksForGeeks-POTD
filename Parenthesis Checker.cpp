class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        for(char &c : x){
            if(c=='(' || c=='{' || c=='[')
                st.push(c);
            if(c==')'){
                if(st.size()>0 && st.top()=='(')
                    st.pop();
                else return false;
            }
            if(c=='}'){
                if(st.size()>0 && st.top()=='{')
                    st.pop();
                else return false;
            }
            if(c==']'){
                if(st.size()>0 && st.top()=='[')
                    st.pop();
                else return false;
            }
        }
        return st.size()==0;
    }

};