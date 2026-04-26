class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        int i=0, j=0, k=0;
        unordered_set<int> st;
        int n=a.size(), m=b.size(), o=c.size();
        while(i<n && j<m && k<o){
            while(i<n && a[i]<b[j]) i++;
            if(i==n) break;
            if(a[i] != b[j]){
                j++;
                continue;
            }
            while(k<o && c[k]<b[j]) k++;
            if(k==o) break;
            if(c[k] != b[j]){
                j++;
                continue;
            }
            if(a[i] == b[j] && c[k] == b[j]){
                st.insert(b[j]);
                i++, j++, k++;
            }
        }
        vector<int> res(st.begin(), st.end());
        sort(res.begin(), res.end());
        return res;
    }
};