class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {

        // Your code here
        vector<int> idx(maxx+2);
        for(int i=0; i<n; i++){
            idx[l[i]]++;
            idx[r[i]+1]--;
        }
        int res=0;
        for(int i=1; i<maxx+2; i++){
            idx[i] += idx[i-1];
            if(idx[i]>idx[res])
                res=i;
        }
        return res;
    }
};
