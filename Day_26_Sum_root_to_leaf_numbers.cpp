/*
---------Question-------------

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

--------Solution Approach----------

Recursively adding each digit from right and left node.

----------Solution-------------

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
    int ans;
    void helper(TreeNode* node,int prevSum){
        if(node==NULL){
            return;
        }
        if(node->right==NULL && node->left==NULL){
            ans+=(prevSum*10+node->val);
            return;
        }
        helper(node->right,prevSum*10+node->val);
        helper(node->left,prevSum*10+node->val);
    }
    int sumNumbers(TreeNode* root) {
        ans=0;
        helper(root,0);
        return ans;
    }
};
