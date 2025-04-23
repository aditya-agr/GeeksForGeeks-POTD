class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int tot = 0;
        for(int x : arr)
            tot ^= x;
        
        int idx = tot & -tot;
            
        int a = 0, b = 0;
        for(int x : arr){
            if(x & idx)
                a ^= x;
            else
                b ^= x;
        }
        if(a > b) return {b, a};
        return {a, b};
    }
};