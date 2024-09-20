class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        // code here
        int cnt=0, mx=0;
        for(int &h : height){
            if(mx<h){
                mx = h;
                cnt++;
            }
        }
        return cnt;
    }
};