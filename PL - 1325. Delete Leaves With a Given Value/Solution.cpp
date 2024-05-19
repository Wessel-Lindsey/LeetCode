/**
 * Definition for a binary tree node->
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        //If a we are at a leaf, return the node
        if(root->left == nullptr && root->right == nullptr){
            if(root->val == target){
                root = nullptr;
            }
            return root;
        }

        //Locate roots that hold leaves
        if(root->left != nullptr){
            root->left = removeLeafNodes(root->left, target);
        }
        if(root->right != nullptr){
            root->right = removeLeafNodes(root->right, target);
        }

        // If all that is left is a single node, check that node
        if(root->left == nullptr && root->right == nullptr && root->val == target){
            root = nullptr;
        }
            
        return root;
    }

};
