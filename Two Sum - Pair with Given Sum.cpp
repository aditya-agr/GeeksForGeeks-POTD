class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(), arr.end());
        int i=0, j=arr.size()-1;
        while(i<j){
            int curr = arr[i] + arr[j];
            if(curr == target)
                return true;
            else if(curr > target)
                j--;
            else 
                i++;
        }
        return false;
    }
};