class Solution {
  public:
    string chooseSwap(string &s) {
        // code here
        vector<bool> ch(26);
        for(char c : s)
            ch[c-'a'] = true;
            
        int n = s.length();
        int flag = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<s[i]-'a'; j++){
                char a = s[i];
                char b = 'a'+j;
                if(ch[b-'a']){
                    for(int k=0; k<n; k++){
                        if(s[k] == a)
                            s[k] = b;
                        else if(s[k] == b)
                            s[k] = a;
                    }
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
            ch[s[i]-'a'] = false;
        }
        return s;
    }
};
