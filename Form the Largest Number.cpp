class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<string> v(n);
        
        for(int i=0; i<n; i++)
            v[i] = to_string(arr[i]);
            
        auto comp = [&](string a, string b){
            if(a+b > b+a)
                return false;
            return true;
        }; 
        sort(v.rbegin(), v.rend(), comp);
        
        string res = "";
        for(int i=0; i<n; i++) 
            res += v[i];
            
        int m = res.length(), i=0;
        while(i<m-1 && res[i]=='0')
            i++;
            
        return res.substr(i);
    }
};