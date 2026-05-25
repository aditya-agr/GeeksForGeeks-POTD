class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        int count = 0;
        
        for(int num : arr){
            if(num >= start && num <= end){
                count++;
            }
        }
        
        if((end - start + 1) == count) 
            return true;
        return false;
    }
};
