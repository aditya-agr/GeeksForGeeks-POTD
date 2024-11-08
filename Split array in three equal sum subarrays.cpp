class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        int sum=0;
        for(int x : arr)
            sum += x;
        if(sum%3) 
            return {-1, -1};
        int target = sum/3;
        vector<int> res;
        sum=0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum == target){
                sum = 0;
                res.push_back(i);
            }
            if(res.size()==2)
                break;
        }
        if(res.size()==2)
            return res;
        return {-1,-1};
    }
};