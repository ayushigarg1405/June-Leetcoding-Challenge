**Question**

Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1

**Solution Approach**
For every node starting from root, interchange the left and right nodes.

**Solution**

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
    void switchNodes(TreeNode *&root){
        if(root->left==NULL and root->right==NULL){
            return;
        }
        TreeNode *temp=NULL;
        temp=root->left;
        root->left=root->right;
        root->right=temp;
        if(root->left!=NULL)
            switchNodes(root->left);
        if(root->right!=NULL)
            switchNodes(root->right);
        
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return root;
        switchNodes(root);
        return root;
        
    }
};
