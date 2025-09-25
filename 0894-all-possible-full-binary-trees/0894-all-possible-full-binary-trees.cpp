/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(): val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        // If n is even, no full binary tree possible
        if (n % 2 == 0) return {};
        return helper(n);
    }

private:
    unordered_map<int, vector<TreeNode*>> memo;

    vector<TreeNode*> helper(int n) {
        if (memo.count(n)) {
            return memo[n];
        }

        vector<TreeNode*> res;

        if (n == 1) {
            // base case: one node, leaf
            TreeNode* leaf = new TreeNode(0);
            res.push_back(leaf);
        } else {
            // root uses 1 node, rest n-1 to split
            // left subtree size i, right subtree size = n - 1 - i
            for (int i = 1; i < n; i += 2) {
                int j = n - 1 - i;
                // i and j will both be odd when starting from odd n
                vector<TreeNode*> leftTrees = helper(i);
                vector<TreeNode*> rightTrees = helper(j);

                for (TreeNode* L : leftTrees) {
                    for (TreeNode* R : rightTrees) {
                        TreeNode* root = new TreeNode(0);
                        root->left = L;
                        root->right = R;
                        res.push_back(root);
                    }
                }
            }
        }

        memo[n] = res;
        return res;
    }
};
