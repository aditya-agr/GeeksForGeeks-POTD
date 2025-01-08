
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int cnt = 0;
        for(int i=n-1; i>=0; i--){
            int l=0, h=i-1;
            while(l<h){
                int sum = arr[l]+arr[h];
                if(sum <= arr[i])
                    l++;
                else{
                    cnt += h-l;
                    h--;
                }
            }
        }
        return cnt;
    }
};
