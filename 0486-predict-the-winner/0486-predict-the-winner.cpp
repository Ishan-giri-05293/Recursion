class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, INT_MIN));
        int diff = dfs(nums, 0, n - 1, memo);
        return diff >= 0;
    }

    // Wrapper so harnesses that call the lowercase name also work
    bool predictTheWinner(vector<int>& nums) {
        return PredictTheWinner(nums);
    }

private:
    int dfs(const vector<int>& nums, int i, int j, vector<vector<int>>& memo) {
        if (i > j) return 0;
        if (i == j) return nums[i];
        if (memo[i][j] != INT_MIN) return memo[i][j];
        int pickLeft = nums[i] - dfs(nums, i + 1, j, memo);
        int pickRight = nums[j] - dfs(nums, i, j - 1, memo);
        return memo[i][j] = max(pickLeft, pickRight);
    }
};
