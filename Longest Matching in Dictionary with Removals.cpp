class Solution {
  public:
    string findLongestWord(string &s, vector<string> &d) {
        // code here
        auto comp = [](string &a, string &b){
            if(a.size() == b.size())
                return a > b;
            return a.size() < b.size();
        };
        sort(d.rbegin(), d.rend(), comp);
        int sz = d.size();
        int mx = 0;
        int n = s.size();
        for(int i=0; i<sz; i++){
            int m = d[i].size();
            int j=0, k=0;
            while(j<n && k<m){
                if(s[j] == d[i][k])
                    k++;
                j++;
            }
            if(k == m)
                return d[i];
        }
        return "";
    }
};