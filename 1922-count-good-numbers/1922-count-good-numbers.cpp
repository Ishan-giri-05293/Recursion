class Solution {
public:
    int countGoodNumbers(long long n) {
        const long long MOD = 1000000007;
        // fast exponentiation mod
        auto modPow = [&](long long base, long long exp) {
            long long result = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp & 1LL) {
                    result = (result * base) % MOD;
                }
                base = (base * base) % MOD;
                exp >>= 1LL;
            }
            return result;
        };

        long long evenCount = (n + 1) / 2;  // ceil(n/2)
        long long oddCount = n / 2;         // floor(n/2)

        long long partEven = modPow(5, evenCount);
        long long partOdd = modPow(4, oddCount);

        long long ans = (partEven * partOdd) % MOD;
        return (int)ans;
    }
};
