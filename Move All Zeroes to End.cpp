class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> temp(n, 0);
        int i=0;
        for(int x : arr)
            if(x!=0) temp[i++] = x;
        arr = temp;
    }
};