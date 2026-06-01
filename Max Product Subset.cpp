class Solution {
    static const long long MOD = 1000000007LL;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;

        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

  public:
    int findMaxProduct(vector<int>& arr) {
        int n = (int)arr.size();

        if (n == 1) {
            return arr[0];
        }

        int zeroCount = 0;
        int positiveCount = 0;
        int negativeCount = 0;

        int minNegAbs = 11;

        long long product = 1;

        for (int x : arr) {
            if (x == 0) {
                zeroCount++;
                continue;
            }

            if (x > 0) {
                positiveCount++;
            } else {
                negativeCount++;
                minNegAbs = min(minNegAbs, abs(x));
            }

            product = (product * (long long)abs(x)) % MOD;
        }

        if (zeroCount == n) {
            return 0;
        }

        if (negativeCount == 1 && positiveCount == 0) {
            return 0;
        }

        if (negativeCount % 2 == 1) {
            long long inv = modPow(minNegAbs, MOD - 2);
            product = (product * inv) % MOD;
        }

        return (int)product;
    }
};