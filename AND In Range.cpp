class Solution {
  public:
    int andInRange(int l, int r) {
        // code here
        int res = 0;
        long long mask = 1;
        int count = r-l+1;
        while(mask <= r){
            if(count<=mask && l&mask && r&mask)
                res += mask;
            else if(l&mask || r&mask)
                res = 0;
            mask = mask<<1;
        }
        return res;
    }
};
