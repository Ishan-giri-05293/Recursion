class Solution {
public:
    int lastRemaining(int n) {
        long head = 1;
        long step = 1;
        long remaining = n;
        bool leftToRight = true;

        while (remaining > 1) {
            if (leftToRight || (remaining % 2 == 1)) {
                head += step;
            }
            // No matter what, after this round:
            remaining /= 2;
            step *= 2;
            leftToRight = !leftToRight;
        }

        return (int)head;
    }
};
