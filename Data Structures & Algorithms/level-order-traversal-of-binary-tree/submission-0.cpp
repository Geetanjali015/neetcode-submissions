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

class Solution { //DFS o(n)
public:
    vector<vector<int>>res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root,0);
        return res;
    }
    void dfs(TreeNode* node, int depth){
        if(!node) return ;

        if(res.size()==depth){ //create new level if visiting first time res=[[1][2]] d=2
            res.push_back(vector<int>()); //res=[[1],[2],[ ]]
        }
        res[depth].push_back(node->val); //res= [[1],[2],[4]]
        dfs(node->left,depth+1);
        dfs(node->right,depth+1);

    }

};
