class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        pair<int, int> last = {0, k};
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] != '0'){
                if(k) 
                    k--;
                else
                    break;
            }
            else{
                last = {i+1, k};
            }
        }
        int i = last.first;
        int remK = last.second;
        stack<char> st;
        while(i<n){
            while(!st.empty() && remK && st.top() > s[i]){
                remK--;
                st.pop();
            }
            st.push(s[i]);
            i++;
        }
        while(!st.empty() && remK){
            remK--;
            st.pop();
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        if(ans == "")
            ans = '0';
        return ans;
    }
};