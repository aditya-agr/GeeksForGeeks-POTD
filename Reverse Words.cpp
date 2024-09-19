class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        stringstream ss(str);
        string word;
        stack<string> st;
        while(getline(ss, word, '.'))
            st.push(word);
        string res="";
        while(st.size()){
            res += st.top();
            res += ".";
            st.pop();
        }
        res.pop_back();
        return res;
    }
    
};