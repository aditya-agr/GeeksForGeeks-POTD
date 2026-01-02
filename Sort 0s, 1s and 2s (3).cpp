class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int l=0, mid=0, h=arr.size()-1;
        while(mid <= h){
            if(arr[mid] == 0)
                swap(arr[mid++], arr[l++]);
            else if(arr[mid] == 2)
                swap(arr[mid], arr[h--]);
            else
                mid++;
        }
    }
};