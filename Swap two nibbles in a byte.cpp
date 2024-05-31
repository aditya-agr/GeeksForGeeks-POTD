class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        int t = n;
        n = n<<4;
        t = t>>4;
        return (n|t)&255;
    }
};