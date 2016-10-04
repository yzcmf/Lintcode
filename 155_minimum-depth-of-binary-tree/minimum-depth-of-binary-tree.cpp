/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/minimum-depth-of-binary-tree
@Language: C++
@Datetime: 16-09-14 05:18
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
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        if(root==NULL) return 0;
        
        int leftchild = minDepth(root->left);
        int rightchild = minDepth(root->right);
        
        if(root->left==NULL || root->right==NULL)
        {
            return max(leftchild,rightchild)+1;
        }
        else
        {
        return min(leftchild,rightchild)+1;
        }
    }
};