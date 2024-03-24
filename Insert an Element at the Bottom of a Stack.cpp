class Solution{
public:
    stack<int> insertAtBottom(stack<int> st,int x){
        stack<int> sta;
        while(!st.empty()){
            int tp = st.top();
            sta.push(tp);
            st.pop();
        }
        sta.push(x);
        while(!sta.empty()){
            int tp = sta.top();
            st.push(tp);
            sta.pop();
        }
        return st;
    }
};