class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int> st;
        for(string s : arr){
            int tp1 = INT_MIN;
            if(!st.empty()){
                tp1 = st.top();
                st.pop();
            }
            int tp2 = INT_MIN;
            if(!st.empty()){
                tp2 = st.top();
                st.pop();
            }
            if(s == "+")
                st.push(tp2+tp1);
            else if(s == "-")
                st.push(tp2-tp1);
            else if(s == "*")
                st.push(tp2*tp1);
            else if(s == "/")
                st.push(floor(tp2/(tp1*1.0)));
            else if(s == "^")
                st.push(pow(tp2,tp1));
            else{
                int num = stoi(s);
                if(tp2 != INT_MIN) st.push(tp2);
                if(tp1 != INT_MIN) st.push(tp1);
                st.push(num);
            }
        }
        return st.top();
    }
};