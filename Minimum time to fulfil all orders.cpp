class Solution {
  public:
    bool check(vector<int> &ranks, int &t, int &n){
        int cnt = 0;
        for(int x : ranks){
            int c = t*2/x;
            int s = sqrt(c);
            if(s*(s+1) > c)
                s--;
            cnt += s;
        }
        return cnt>=n;
    }
    int minTime(vector<int>& ranks, int n) {
        // code here
        sort(ranks.begin(), ranks.end());
        int m = ranks.size();
        int l = 0;
        int h = ranks[0]*n*(n+1)/2;
        
        int res;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(ranks, mid, n)){
                res = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};