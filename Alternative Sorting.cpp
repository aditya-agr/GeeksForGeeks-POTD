
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        vector<int> res(n);
        sort(arr.rbegin(), arr.rend());
        int i=0, j=n-1, k=0;
        while(i<=j){
            res[k++] = arr[i++];
            if(i<=j) res[k++] = arr[j--];
        }
        return res;
    }
};
