class Solution {
  public:
    bool check(int n, int d){
        int sum = 0, temp = n;
        while(n){
            sum += n%10;
            n /= 10;
        }
        return temp-sum >= d;
    }
    int getCount(int n, int d) {
        // code here
        int l=1, h=n;
        int res = 0;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(check(mid, d)){
                res = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        return res==0 ? 0 : n-res+1;
    }
};