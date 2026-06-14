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

class Solution { //brute o(n2)
public:
    int diameterOfBinaryTree(TreeNode* root) { 
        if(!root) return 0;
        int leftH=maxHeight(root->left); //to calc dia , height is needed
        int rightH=maxHeight(root->right);
        int dia=leftH+rightH; //dia through curr node
        int subtree=max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)); //dia inside children
        return max(dia,subtree);
    }
    int maxHeight(TreeNode* root){ //helper function
        if(!root) return 0;
        return 1+ max(maxHeight(root->left), maxHeight(root->right));  // Current node + taller subtree
    }
};
