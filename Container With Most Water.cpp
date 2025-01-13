class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int l=0, h=n-1;
        int res = 0;
        while(l<h){
            int area = min(arr[l], arr[h]) * (h-l);
            res = max(res, area);
            if(arr[l] <= arr[h])
                l++;
            else
                h--;
        }
        return res;
    }
};