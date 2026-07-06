/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<int, int> m; //el->idx
    TreeNode* solve(vector<int>&preorder, int s, int e, int&idx){
        if(s>e) return nullptr;
        int i = m[preorder[idx]];
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        root ->left = solve(preorder, s, i-1, idx);
        root->right = solve(preorder, i+1, e, idx);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i<n; ++i){
            m[inorder[i]] = i;
        }
        int idx = 0;
        return solve(preorder, 0, n-1, idx);
    }
};