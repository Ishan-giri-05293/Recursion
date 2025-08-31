class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;   // negative & zero are not powers of two
        if (n == 1) return true;    // base: 2^0 = 1
        if (n % 2 != 0) return false; // any odd > 1 can't be power of two
        return isPowerOfTwo(n / 2);

    }
};