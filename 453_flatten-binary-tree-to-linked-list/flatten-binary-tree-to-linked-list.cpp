/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/flatten-binary-tree-to-linked-list
@Language: C++
@Datetime: 16-09-20 07:42
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        // write your code here
       if(root == NULL) return;
       vector<TreeNode*> allnode; 
       //Storing the TreeNodes and reorder them; 
       preorderTraversal(root,allnode);
       int n=allnode.size();
       
       for(int i=0;i<n-1;i++)
       {
           allnode[i]->left = NULL;
           allnode[i]->right = allnode[i+1];
       }
       
       allnode[n-1]->left = allnode[n-1]->right = NULL;
    }

private:    
    void preorderTraversal(TreeNode *root,vector<TreeNode*>& allnode)
    {
        
        if(root == NULL) return;
        
        allnode.push_back(root);
        preorderTraversal(root->left,allnode);
        preorderTraversal(root->right,allnode);
        
        return;
    }
};