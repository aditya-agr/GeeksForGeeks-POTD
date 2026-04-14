class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string res = "";
        for(char &c : s){
            if(c != ' ')
                res += c;
        }
        return res;
    }
};