/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/binary-tree-zigzag-level-order-traversal
@Language: C++
@Datetime: 16-09-17 03:52
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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> res;
        if(root == NULL) return res;
        
        queue<TreeNode *>q;
        q.push(root);
        int reversed_flag = 0;
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int> list;
            
            for(int i=0;i<n;i++)
            {
              TreeNode * node = q.front();
              q.pop();
              list.push_back(node->val);
              if(node->left) q.push(node->left);
              if(node->right) q.push(node->right);
            }
            
            if(reversed_flag % 2 ==1 ) reverse(list.begin(),list.end());
            reversed_flag++;
            res.push_back(list);
        }
        
        return res;
    }
};