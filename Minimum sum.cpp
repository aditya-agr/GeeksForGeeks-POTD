class Solution {
  public:
    string sum(string &a, string &b){
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = a.size();
        int m = b.size();
        string res = "";
        int carry=0, i=0, len=max(n,m);
        while(i < len){
            int num = carry;
            if(i<n) num += (a[i]-'0');
            if(i<m) num += (b[i]-'0');
            carry = num/10;
            num %= 10;
            res += ('0'+num);
            i++;
        }
        if(carry)
            res += ('0'+carry);
        reverse(res.begin(), res.end());
        return res;
    }
    string minSum(vector<int> &arr) {
        // code here
        string first = "";
        string second = "";
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            if(arr[i] == 0) continue;
            if(i%2)
                first += ('0'+arr[i]);
            else
                second += ('0'+arr[i]);
        }
        string res = sum(first, second);
        return res;
        
    }
};