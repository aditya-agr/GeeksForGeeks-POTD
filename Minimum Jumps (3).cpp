class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        if(arr[0] == 0)
            return -1;
        int n = arr.size();
        int idx = arr[0], st = arr[0], cnt = 1;
        for(int i=1; i<n; i++){
            if(i == n-1)
                return cnt;
            idx = max(idx, i+arr[i]);
            st--;
            if(st == 0){
                cnt++;
                if(idx <= i)
                    return -1;
                st = idx-i;
            }
        }
        return -1;
    }
};
