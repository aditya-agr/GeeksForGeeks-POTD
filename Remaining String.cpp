class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
        int n=s.length();
        for(int i=0; i<n; i++){
            if(s[i]==ch){
                count--;
                if(count==0)
                    return s.substr(i+1);
            }
        }
        return "";
    }
};