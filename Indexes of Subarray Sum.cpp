class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        int i=0, j=0, curr=0;
        while(i<n){
            while(j<n && curr<target){
                curr += arr[j];
                j++;
            }
            if(curr == target)
                return {i+1, j};
            curr -= arr[i];
            i++;
        }
        return {-1};
    }
};