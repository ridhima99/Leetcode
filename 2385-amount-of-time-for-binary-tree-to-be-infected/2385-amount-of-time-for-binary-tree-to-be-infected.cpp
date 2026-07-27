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
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* markParents(TreeNode* root, int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* startNode = nullptr;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->val == start)
                startNode = node;
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return startNode;
    }

    int amountOfTime(TreeNode* root, int start) {
        TreeNode* startNode = markParents(root, start);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;
        q.push(startNode);
        vis.insert(startNode);
        int time = -1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !vis.count(node->left)) {
                    vis.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && !vis.count(node->right)) {
                    vis.insert(node->right);
                    q.push(node->right);
                }
                if (parent.count(node) && !vis.count(parent[node])) {
                    vis.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            time++;
        }
        return time;
    }
};