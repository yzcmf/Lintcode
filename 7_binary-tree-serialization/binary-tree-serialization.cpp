/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/binary-tree-serialization
@Language: C++
@Datetime: 16-09-20 07:11
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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        ostringstream out;
        serialize(root,out);
        return out.str();
    }
    
    void serialize(TreeNode * root,ostringstream& out)
    {
        if(root)
        {
            out << root->val << ' ';
            serialize(root->left,out);
            serialize(root->right,out);
        }
        else
        {
            out << '#' << ' ';
        }
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        
        istringstream in(data);
        return deserialize(in);
    }
    
    TreeNode* deserialize(istringstream& in)
    {
        string val;
        in >> val;
        if(val == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};
