/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/identical-binary-tree
@Language: C++
@Datetime: 16-09-14 04:06
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
     * @aaram a, b, the root of binary trees.
     * @return true if they are identical, or false.
     */
    bool isIdentical(TreeNode* a, TreeNode* b) {
        // Write your code here

        
        if(a==NULL && b==NULL) return true;
        if(a==NULL || b==NULL) return false;
        
     return a->val == b->val && isIdentical(a->left,b->left) && isIdentical(a->right,b->right);
    
    //         if(!a && !b) return true;
    // if(!a || !b) return false;
    // return a->val == b->val && isIdentical(a->left,b->left) && isIdentical(a->right,b->right);
        
    }

};