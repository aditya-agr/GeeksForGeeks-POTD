class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int n = s.length();
        int m = p.length();
        if(n<m) 
            return "-1";
        vector<int> S(26), P(26);
        int st=-1, len=INT_MAX, c=0, c2=0;
        for(int i=0; i<m; i++){
            P[p[i]-'a']++;
            if(P[p[i]-'a']==1)
                c++;
        }
        int j=0;
        for(int i=0; i<n; i++){
            S[s[i]-'a']++;
            if(S[s[i]-'a']==P[s[i]-'a'])
                c2++;
            if(c==c2){
                while(S[s[j]-'a']>P[s[j]-'a'])
                    S[s[j++]-'a']--;
                if(len > i-j+1){
                    st = j;
                    len = i-j+1;
                }
            }
        }
        if(st==-1)
            return "-1";
        return s.substr(st, len);
    }
};