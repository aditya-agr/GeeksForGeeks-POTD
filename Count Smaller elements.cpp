class Solution {
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        // code 
        int n = arr.size();
        vector<int> ans(n), temp;
        temp.push_back(arr[n-1]);
        
        for(int i=n-2; i>=0; i--){
            int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            ans[i] = idx;
            temp.insert(temp.begin()+idx, arr[i]);
        }
        return ans;
    }
};