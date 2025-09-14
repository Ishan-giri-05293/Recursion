class Solution {
public:
    double myPow(double x, int n) {
        // Convert n to long long to avoid overflow when n = INT_MIN
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }
    
private:
    double fastPow(double x, long long n) {
        // Base case
        if (n == 0) {
            return 1.0;
        }
        
        // Recurse on half
        double half = fastPow(x, n / 2);
        
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};
