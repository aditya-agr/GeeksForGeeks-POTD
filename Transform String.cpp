class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a != b)
            return -1;
            
        int n = s1.size();
        int i=n-1, j=n-1;
        while(i>=0){
            if(s2[j] == s1[i])
                j--;
            i--;
        }
        return j+1;
        
}
};
