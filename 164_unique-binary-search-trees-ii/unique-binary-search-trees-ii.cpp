/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/unique-binary-search-trees-ii
@Language: C++
@Datetime: 16-10-01 03:31
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
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode*> generateTrees(int n) {
        // write your code here
        return genBST(1,n);
    }
    
     vector<TreeNode*> genBST(int min,int max)
     {
         vector<TreeNode*> res;
         if(min>max)
         {
             res.push_back(NULL);
             return res;
         }
         
         for(int i=min;i<=max;i++)
         {
           vector<TreeNode *> leftSubTree = genBST(min,i-1);
           vector<TreeNode *> rightSubTree = genBST(i+1,max);  
          
           for(int j=0;j<leftSubTree.size();j++)
           {
              for(int k=0;k<rightSubTree.size();k++)
              {
                TreeNode *root = new TreeNode(i);  
                root->left = leftSubTree[j];
                root->right = rightSubTree[k];  
                res.push_back(root);  
              }
           }
           
         }
         return res;
     }
};
//http://bangbingsyb.blogspot.com/2014/11/leetcode-unique-binary-search-trees-i-ii.html