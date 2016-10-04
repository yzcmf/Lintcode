/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/binary-tree-level-order-traversal
@Language: C++
@Datetime: 16-09-17 03:34
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
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here

        vector<vector<int>>res;
        if(root == NULL)
        return res;
       
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> list;
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
            TreeNode* node = q.front();
            q.pop();
            list.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            }
            
            res.push_back(list);
        }
        
        return res;
    }
   
};
