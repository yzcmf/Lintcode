/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/binary-tree-postorder-traversal
@Language: C++
@Datetime: 16-09-13 07:15
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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        postorderTraversal(root,res);
        
        return res;
    }
    
private:
    void postorderTraversal(TreeNode *root,vector<int>& res)
    {
        if(root == NULL) return;
        postorderTraversal(root->left,res);
        postorderTraversal(root->right,res);
        res.push_back(root->val);
    }  
};