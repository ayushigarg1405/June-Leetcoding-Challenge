/* --------Question----------

Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.

---------Solution Approach-----------

If right subtree is full - total nodes are - 2^(h) - 1
If right subtree is empty and left is full - total nodes are - 2^(h-1) - 1

---------Solution-----------
*/

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
    int count(TreeNode *root){
        if(root==NULL)
            return 0;
        int left = count(root->left);
        int right= count(root->right);
        return 1+left+right;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        return count(root);
    }
};
