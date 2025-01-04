class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int n = arr.size();
        int cnt = 0;
        for(int i=0; i<n-2; i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = arr[i]+arr[j]+arr[k];
                if(sum > target)
                    k--;
                else if(sum < target)
                    j++;
                else{
                    cnt++;
                    int temp = j+1;
                    while(temp<k && arr[temp]==arr[temp-1]){
                        temp++;
                        cnt++;
                    }
                    k--;
                }
            }
        }
        return cnt;
    }
};