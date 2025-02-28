class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<string> st;
        for(string s : arr){
            if(s == "+"){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                st.push(to_string(b+a));
            }
            else if(s == "-"){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                st.push(to_string(b-a));
            }
            else if(s == "/"){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                st.push(to_string(b/a));
            }
            else if(s == "*"){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                st.push(to_string(b*a));
            }
            else
                st.push(s);
        }
        return stoi(st.top());
    }
};