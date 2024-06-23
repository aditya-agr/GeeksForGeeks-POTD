class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        vector<int> ans;
        stack<int> st;
        int count=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='('){
                count++;
                ans.push_back(count);
                st.push(count);
            }
            else if(str[i]==')'){
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};