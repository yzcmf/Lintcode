/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/validate-binary-search-tree
@Language: C++
@Datetime: 16-09-18 04:38
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
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        vector<int>list;
        inorder(root,list);
        
        for(int i=1;i<list.size();i++)
        {
            if(list[i]<=list[i-1])
            return false;
        }
        
        return true;
    }
    
    void inorder(TreeNode *root,vector<int>& list)
    {
        if(root == NULL) return;
        
        inorder(root->left,list);
        list.push_back(root->val);
        inorder(root->right,list);
    }
};