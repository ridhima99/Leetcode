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
    int findMax(TreeNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root-> val>key){
            root->left = deleteNode(root->left,key);
        }else if(root-> val < key){
            root->right = deleteNode(root->right,key);
        }else{
            //no child
            if(root->left == nullptr && root->right == nullptr) return nullptr;
            //one child
            if(root->left == nullptr) return root->right;
            else if(root->right == nullptr) return root->left;
            //two child
            int val = findMax(root->left);
            root->val = val;
            root->left = deleteNode(root->left,val);
        }
        return root;
    }
};