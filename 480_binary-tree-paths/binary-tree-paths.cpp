/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/binary-tree-paths
@Language: C++
@Datetime: 16-09-13 07:25
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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        
        vector<string> res;
        vector<int> path;
        backtrack(root, path, res);
        return res;
    }
    
private: 
    
    void backtrack(TreeNode* root, vector<int>& path, vector<string>& res){
        if(root == NULL){
            return;
        }
        else if(root->left == NULL && root->right == NULL){
            string tmp = "";
            for(int i = 0; i < path.size(); ++i){
                tmp += to_string(path[i]);
                tmp += "->";
            }
            tmp += to_string(root->val);
            res.push_back(tmp);
            return;
        }
        if(root->left != NULL){
            path.push_back(root->val);
            backtrack(root->left, path, res);
            path.pop_back();
        }
        if(root->right != NULL){
            path.push_back(root->val);
            backtrack(root->right, path, res);
            path.pop_back();
        }
    }
    
};