class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        stack<int> st;
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(arr[i]);
            }
            else{
                if ((arr[i]>0 && st.top()<0) || (arr[i]<0 && st.top()>0)){
                    int tp = st.top();
                    st.pop();
                    if(abs(tp) == abs(arr[i]))
                        continue;
                    if(abs(tp) > abs(arr[i]))
                        st.push(tp);
                    else
                        st.push(arr[i]);
                }
                else
                    st.push(arr[i]);
            }
            while(st.size()>1){
                int tp = st.top();
                st.pop();
                if ((tp>0 && st.top()<0) || (tp<0 && st.top()>0)){
                    int tp2 = st.top();
                    st.pop();
                    if(abs(tp) == abs(tp2))
                        continue;
                    if(abs(tp) > abs(tp2))
                        st.push(tp);
                    else
                        st.push(tp2);
                }
                else{
                    st.push(tp);
                    break;
                }
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};