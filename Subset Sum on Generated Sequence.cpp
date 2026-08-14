class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        // code here
        vector<long long> num;
        num.push_back(s);
        int n = arr.size();
        int sum = s;
        for(int i=0; i<n; i++){
            int cur = sum+arr[i];
            num.push_back(cur);
            sum += cur;
            if(sum > x)
                break;
        }
        long long rem = x;
        int m = num.size();
        for(int i=m-1; i>=0; i--){
            if(num[i]<=rem)
                rem -= num[i];
            if(rem == 0)
                return true;
        }
        return false;
    }
};