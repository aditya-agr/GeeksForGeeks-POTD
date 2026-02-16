class Solution {
  public:   
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin(), arr.end());
        int ed = arr[0][1];
        int n = arr.size();
        for(int i=1; i<n; i++){
            if(arr[i][0] < ed)
                return false;
            ed = arr[i][1];
        }
        return true;
    }
};