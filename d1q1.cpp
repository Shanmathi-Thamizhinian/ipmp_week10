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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode= new TreeNode(val);
        TreeNode* node=root, *parent;
        if(root==NULL) return newnode;
        while(node){
            if(node->val<val) {parent=node; node=node->right;}
            else{ parent=node; node=node->left; }
        }
       // TreeNode* newnode= new TreeNode(val);
        if(val>parent->val) parent->right=newnode;
        else parent->left=newnode;
        return root;
    }
};
