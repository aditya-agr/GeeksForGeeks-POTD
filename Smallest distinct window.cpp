class Solution {
  public:
    int findSubString(string& str) {
        // code here
        unordered_set<char> st;
        for(char c : str)
            st.insert(c);
        int k = st.size();
        int i=0, j=0;
        int n = str.size();
        int res = n;
        unordered_map<int, int> mp;
        while(j<n){
            mp[str[j]]++;
            while(mp.size() == k){
                res = min(res, j-i+1);
                mp[str[i]]--;
                if(mp[str[i]] == 0)
                    mp.erase(str[i]);
                i++;
            }
            j++;
        }
        return res;
        
    }
};