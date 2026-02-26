class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        unordered_map<char,char>mp;
        unordered_set<char>st;
        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            char c1=s1[i];
            char c2=s2[i];
            if(mp.find(c1)!=mp.end())
            {
                if(mp[c1]!=c2)
                    return false;
            }
            else
            {
                if(st.find(c2)!=st.end())
                {
                    return false;
                }
                mp[c1]=c2;
                st.insert(c2);
            }
        }
        return true;
    }
};