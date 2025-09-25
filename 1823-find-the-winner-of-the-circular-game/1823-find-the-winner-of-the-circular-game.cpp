class Solution {
public:
    int findTheWinner(int n, int k) {
        // compute 0-indexed winner f(n, k)
        int winner0 = josephus(n, k);
        // convert to 1-index
        return winner0 + 1;
    }

private:
    int josephus(int n, int k) {
        if (n == 1) {
            return 0;
        }
        int prev = josephus(n - 1, k);
        return (prev + k) % n;
    }
};
