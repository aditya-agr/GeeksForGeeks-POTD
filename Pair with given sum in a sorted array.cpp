class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int n = arr.size();
        int l=0, h=n-1;
        int cnt = 0;
        while(l<=h){
            int sum = arr[l]+arr[h];
            if(sum < target)
                l++;
            else if(sum > target)
                h--;
            else{
                int temp = l;
                while(temp<h && arr[temp]==arr[l]){
                    cnt++;
                    temp++;
                }
                h--;
            }
        }
        return cnt;
    }
};