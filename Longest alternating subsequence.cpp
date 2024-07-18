class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
        int incre=1; 
        int decre=1; 
        int n = arr.size();
        for(int i=1; i<n; i++){
            if(arr[i-1] > arr[i]) 
                decre = incre+1;
            else if(arr[i-1] < arr[i])
                incre = decre+1;
        }
        return max(incre, decre);
    }
};