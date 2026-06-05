class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int n = s.length();
        if(__builtin_popcount(n) == 1)
            k /= 2;
        else
            k *= 2;
        
        if(k >= n)
            return "-1";
        
        stack<char> st;
        for(char c : s){
            while(!st.empty() && st.top() > c && k > 0){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};