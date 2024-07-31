class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int mn=INT_MAX;
        string str;
        for(auto &s : arr){
            int n = s.length();
            if(n<mn){
                mn = n;
                str = s;
            }
        }
        int idx=INT_MAX;
        for(auto &s : arr){
            int i=0;
            while(s[i]==str[i])
                i++;
            idx = min(idx, i);
        }
        string res = "";
        for(int i=0; i<idx; i++)
            res += str[i];
        return res.empty() ? "-1" : res;
        
    }
};