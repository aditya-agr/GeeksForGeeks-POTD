class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        unordered_set<int> st(b.begin(), b.end());
        vector<int> vec;
        for(int x : a){
            if(st.count(x))
                vec.push_back(x);
        }
        int n = a.size();
        int m = b.size();
        int s = vec.size();
        int i=0, j=0, k=0;
        int res = 0;
        while(i<n || j<m){
            int c = (k<s) ? vec[k] : 1e4+3;
            int sum1 = 0;
            while(i<n && a[i]!=c)
                sum1 += a[i++];
            int sum2 = 0;
            while(j<m && b[j]!=c)
                sum2 += b[j++];
            res += max(sum1, sum2);
            if(c != 1e4+3)
                res += c;
            i++;
            j++;
            k++;
        }
        return res;
    }
};