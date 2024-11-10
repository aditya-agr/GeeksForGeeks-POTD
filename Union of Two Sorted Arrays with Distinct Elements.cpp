class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int> res;
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        while(i<n && j<m){
            if(a[i] < b[j])
                res.push_back(a[i++]);
            else if(a[i] > b[j])
                res.push_back(b[j++]);
            else{
                res.push_back(a[i++]);
                j++;
            }
        }
        while(i<n)
            res.push_back(a[i++]);
    
        while(j<m)
            res.push_back(b[j++]);

        return res;
            
    }
};