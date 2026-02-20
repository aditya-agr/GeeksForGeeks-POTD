class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<string> idx;
        for(int i=0; i<n; i++)
            idx.push_back(to_string(arr[i]));
        auto comp = [](string &a, string &b){
            if(a+b > b+a)
                return true;
            return false;
        };
        sort(idx.begin(), idx.end(), comp);
        string res = "";
        for(string &s : idx)
            res += s;
        int i=0, m=res.length();
        while(i<m-1 && res[i]=='0') i++;
        return res.substr(i);
    }
};