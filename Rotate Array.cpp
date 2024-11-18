class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size();
        vector<int> temp(n);
        d = d%n;
        for(int i=0; i<n; i++){
            if(i<d)
                temp[n-d+i] = arr[i];
            else
                temp[i-d] = arr[i];
        }
        arr = temp;
    }
};
