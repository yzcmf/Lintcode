/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/balanced-binary-tree
@Language: C++
@Datetime: 16-09-13 07:09
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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        //if(root == NULL) return true;
        bool res = true;
        int max_len=maxdepth(root,res);
        
        return res;
    }
    
private:
   int maxdepth(TreeNode *root,bool& res)
   {
       if(root == NULL) return 0;
       
       int leftdepth = maxdepth(root->left,res);
       int rightdepth = maxdepth(root->right,res);
       
       if(abs(leftdepth-rightdepth)>1)
       {
           res = false;
           return INT_MAX;
       }
        
       return  max(leftdepth,rightdepth)+1;  
   }
   
// bool isBalanced(TreeNode *root) {
//         // write your code here
        
//         if (root==NULL) return true;
//         bool result = true;
        
//         maxdepth(result,root);
        
//         return result;
//     }
// private:   
//     int maxdepth (bool &IsBalanced, TreeNode* root)
//     {
//         if(root== NULL) return 0;
        
//         int leftDepth=maxdepth (IsBalanced,root->left);
//         int rigthDepth=maxdepth (IsBalanced,root->right);
        
//         if(abs(leftDepth-rigthDepth)>1)
//         {
//             IsBalanced=false;
//             return INT_MAX;
//         }
        
//         return max(leftDepth,rigthDepth)+1;
//     }
};