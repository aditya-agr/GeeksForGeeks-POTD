class Solution {
  public:
    string profession(int level, int pos) {
        // code here
        long long h = pow(2, 31), l = 1;
        int res = 0;
        while(l < h){
            int mid = l + (h-l)/2;
            if(pos <= mid){
                h = mid;
            }
            else{
                res = 1-res;
                l = mid+1;
            }
        }
        return res == 0 ? "Engineer" : "Doctor";
    }
};