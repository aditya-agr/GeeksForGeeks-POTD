class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int l=0, h=n-1, curr=INT_MAX;
        vector<int> res;
        while(l < h){
            int sum = arr[l] + arr[h];
            if(sum == target)
                return {arr[l], arr[h]};
            else if(sum < target){
                if(target-sum < curr){
                    res = {arr[l], arr[h]};
                    curr = target-sum;
                }
                l++;
            }
            else{
                if(sum-target < curr){
                    curr = sum-target;
                    res = {arr[l], arr[h]};
                }
                h--;
            }
        }
        return res;
    }
};