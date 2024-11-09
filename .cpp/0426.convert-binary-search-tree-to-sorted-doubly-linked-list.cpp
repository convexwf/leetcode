/*
 * @lc app=leetcode id=426 lang=cpp
 *
 * [426] Convert Binary Search Tree to Sorted Doubly Linked List
 */

// @lc code=start
// 1. 递归
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node* leftList = treeToDoublyList(root->left);
        Node* rightList = treeToDoublyList(root->right);
        Node* head = root;
        if (leftList != nullptr) {
            head = leftList;
            Node* leftLastNode = leftList->left;
            leftLastNode->right = root;
            root->left = leftLastNode;
            leftList->left = root;
            root->right = leftList;
        }
        if (rightList != nullptr) {
            Node* rightLastNode = rightList->left;
            head->left = rightLastNode;
            rightLastNode->right = head;
            root->right = rightList;
            rightList->left = root;
        }
        return head;
    }
};
// @lc code=end
