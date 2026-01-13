class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int n = arr.size();
        int c5=0, c10=0;
        for(int i=0; i<n; i++){
            if(arr[i] == 5)
                c5++;
            else if(arr[i] == 10){
                if(c5 <= 0)
                    return false;
                c10++;
                c5--;
            }
            else{
                if(c10 && c5){
                    c5--;
                    c10--;
                }
                else if(c5 >= 3)
                    c5 -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};ss