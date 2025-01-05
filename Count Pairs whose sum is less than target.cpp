class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        sort(arr.begin(), arr.end());
        int cnt = 0, n = arr.size();
        for(int i=0; i<n-1; i++){
            if(arr[i]+arr[i+1]>=target) break;
            int l=i+1, h=n-1, res=0;
            while(l<=h){
                int mid = l + (h-l)/2;
                int sum = arr[i] + arr[mid];
                if(sum < target){
                    res = mid;
                    l = mid+1;
                }
                else
                    h = mid-1;
            }
            cnt += (res - i);
        }
        return cnt;
    }
};
