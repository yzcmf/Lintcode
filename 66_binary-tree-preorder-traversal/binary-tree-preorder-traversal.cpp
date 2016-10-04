/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/binary-tree-preorder-traversal
@Language: C++
@Datetime: 16-09-13 07:14
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        preorderTraversal(root,res);
        
        return res;
    }
    
private:
    void preorderTraversal(TreeNode *root,vector<int>& res)
    {
        if(root == NULL) return;
        res.push_back(root->val);
        preorderTraversal(root->left,res);
        preorderTraversal(root->right,res);
    }    
};
