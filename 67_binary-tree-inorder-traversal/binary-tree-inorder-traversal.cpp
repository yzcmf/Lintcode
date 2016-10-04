/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/binary-tree-inorder-traversal
@Language: C++
@Datetime: 16-09-13 07:12
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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        inorderTraversal(root,res);
        
        return res;
    }
    
private:
    void inorderTraversal(TreeNode *root,vector<int>& res)
    {
        if(root == NULL) return;
        inorderTraversal(root->left,res);
        res.push_back(root->val);
        inorderTraversal(root->right,res);
    }
};