**Question**

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

**Solution Approach**

Keep storing next of node to node until node is not null.

**Solution**

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        ListNode* prev = NULL;
        while(curr->next != NULL){
            prev = curr;
            curr->val = curr->next->val;
            curr = curr->next;
        }
        prev->next = NULL;
        delete(curr);
    }
};

