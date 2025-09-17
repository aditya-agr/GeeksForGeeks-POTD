

class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<char> st;
        for(char c : s){
            if(c != ']')
                st.push(c);
            else{
                string word;
                while(!st.empty() && st.top()!='['){
                    word.push_back(st.top());
                    st.pop();
                }
                reverse(word.begin(), word.end());
                st.pop();
                string k;
                while(!st.empty() && isdigit(st.top())){
                    k.push_back(st.top());
                    st.pop();
                }
                reverse(k.begin(), k.end());
                int n = word.size(), K = stoi(k);
                for(int i=0; i<K; i++)
                    for(int j=0; j<n; j++)
                        st.push(word[j]);
            }
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

