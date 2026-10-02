class Solution {
  public:
    string lexiString(string &s) {
        // code here
        int n = s.length();
          int i = 0, j = 1, k = 0;
    
          // Two-pointer minimum rotation algorithm
          while (i < n && j < n && k < n) {
              char charI = s[(i + k) % n];
              char charJ = s[(j + k) % n];
    
              if (charI == charJ) {
                  k++;
              } else {
                  if (charI > charJ) {
                      i += k + 1;
                  } else {
                      j += k + 1;
                  }
    
                  // Keep the pointers distinct
                  if (i == j) {
                      j++;
                  }
                  k = 0; // Reset matching prefix length
              }
          }
    
          // The smaller index marks the beginning of the optimal rotation
          int startPos = min(i, j);
    
          // Reconstruct and return the rotated string
          return s.substr(startPos) + s.substr(0, startPos);
    }
};