class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        vector<int> last(26);
        int n = s.length();
        for(int i=0; i<n; i++)
            last[s[i]-'a'] = i;
        
        int i = 0, end;
        int res = 0;
        while(i<n){
            end = max(end, last[s[i]-'a']);
            if(i == end)
                res++;
            i++;    
        }
        return res;
    }
};