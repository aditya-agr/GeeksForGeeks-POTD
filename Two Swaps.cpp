class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        int n = arr.size();
        int cnt=0;
        for(int i=1; i<=n; i++){
            while(arr[i-1] != i){
                swap(arr[i-1], arr[arr[i-1]-1]);
                cnt++;
                if(cnt>2)
                    return false;
            }
        }
        return cnt==2 || cnt==0;
    }
};