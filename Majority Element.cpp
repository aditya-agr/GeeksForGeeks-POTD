class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ele = arr[0], cnt = 0;
        for(int x : arr){
            if(x == ele)
                cnt++;
            else{
                cnt--;
                if(cnt == 0){
                    cnt = 1;
                    ele = x;
                }
            }
        }
        cnt = 0;
        for(int x : arr)
            if(x == ele)
                cnt++;
        if(cnt > n/2)
            return ele;
        return -1;
    }
};