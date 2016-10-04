/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/binary-tree-level-order-traversal-ii
@Language: C++
@Datetime: 16-09-17 03:42
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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
        vector<vector<int>>res;
        if(root == NULL) return res;
        
        queue<TreeNode *>q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int>list;
    
            for(int i=0;i<n;i++)
            {
              TreeNode * node = q.front();
              q.pop();    
              list.push_back(node->val);
              if(node->left) q.push(node->left);
              if(node->right) q.push(node->right);     
            }
            
            res.push_back(list);
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};