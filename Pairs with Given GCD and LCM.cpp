class Solution {
  public:
    int pairCount(int x, int y) {
        // code here
        if (y % x != 0) 
            return 0;

        int n = y / x;
        int res = 0;

        // Find coprime factor pairs of n = y / x
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                int j = n / i;
                // Check if the factors are coprime
                if (__gcd(i, j) == 1) {
                    if (i == j) {
                        res += 1; // e.g., (x, x)
                    } else {
                        res += 2; // (a, b) and (b, a) are distinct
                    }
                }
            }
        }
        return res;
    }
};