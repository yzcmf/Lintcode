/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/convert-sorted-array-to-binary-search-tree-with-minimal-height
@Language: C++
@Datetime: 16-09-13 08:44
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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        
        if(A.empty()) return NULL;
        TreeNode* root = sortedArrayToBST(A,0,A.size()-1);
        
        return root;
    }
private:
      TreeNode *sortedArrayToBST(vector<int> &A, int l,int r)
      {
        if(l>r) return NULL; 

        int mid = (l+r)/2;
        TreeNode * root = new TreeNode(A[mid]);
        root->left = sortedArrayToBST(A,l,mid-1);
        root->right = sortedArrayToBST(A,mid+1,r);
        return root;
      }
  
};


