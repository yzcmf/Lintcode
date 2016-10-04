/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/house-robber-iii
@Language: C++
@Datetime: 16-09-22 22:19
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
/*
那么这种问题是很典型的递归问题，我们可以利用回溯法来做，
因为当前的计算需要依赖之前的结果，那么我们对于某一个节点，
如果其左子节点存在，我们通过递归调用函数，算出不包含左子节点返回的值，
同理，如果右子节点存在，算出不包含右子节点返回的值，
那么此节点的最大值可能有两种情况，一种是该节点值加上不包含左子节点和右子节点的返回值之和，
另一种是左右子节点返回值之和不包含当期节点值，取两者的较大值返回即可
*/ 
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode* root) {
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }
    vector<int> helper(TreeNode *root) {
        if (!root) return {0, 0};
        
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        vector<int> res{0, 0};
        //res[0]:左右子节点返回值之和不包含当期节点值
        //res[1]:该节点值加上不包含左子节点和右子节点的返回值之和
        
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        //左右子节点返回值之和不包含当期节点值
        
        res[1] = left[0] + right[0] + root->val;
        //left[0]:左子节点返回值之和不包含左子节点值
        //right[0]:右子节点返回值之和不包含右子节点值
        //该节点值加上不包含左子节点和右子节点的返回值之和
        
        return res;
    }
};