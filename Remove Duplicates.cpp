class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        vector<int> idx(26);
        string res = "";
        for(char &c : str){
            if(!idx[c-'a'])
                res += c;
            idx[c-'a']++;
        }
        return res;
    }
};