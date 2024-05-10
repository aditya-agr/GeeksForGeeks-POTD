class Solution{
public:
    vector<vector<int>> res;
    vector<int> curr;
    void solve(int idx, vector<int> &arr,int k){
        if(k == 0){
            res.push_back(curr);
            return;
        }
        if(idx== arr.size() || k < 0)
            return;
        for(int i=idx; i<arr.size(); i++){
            if(i>idx && arr[i]==arr[i-1]) continue;
            curr.push_back(arr[i]);
            solve(i+1, arr, k-arr[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(), arr.end());
        solve(0, arr, k);
        return res;
    }
};