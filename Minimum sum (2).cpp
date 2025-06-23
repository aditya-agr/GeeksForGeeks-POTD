class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        string s1="", s2="";
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(i%2 == 0)
                s1 += (arr[i]+'0');
            else
                s2 += (arr[i]+'0');
        }
        string res="";
        int i = s1.length()-1;
        int j = s2.length()-1;
        int c = 0;
        while(i>=0 || j>=0){
            int sum = c;
            if(i>=0){
                sum += (s1[i]-'0');
                i--;
            }
            if(j>=0){
                sum += (s2[j]-'0');
                j--;
            }
            res += (sum%10 + '0');
            c = sum/10;
        }
        res += (c + '0');
        while(!res.empty() && res.back()=='0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};