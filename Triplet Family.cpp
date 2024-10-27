
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i=n-1; i>1; i--){
            int j=0, k=i-1;
            while(j<k){
                int sum = arr[j]+arr[k];
                if(sum == arr[i])
                    return true;
                else if(sum < arr[i])
                    j++;
                else
                    k--;
            }
        }
        return false;
    }
};