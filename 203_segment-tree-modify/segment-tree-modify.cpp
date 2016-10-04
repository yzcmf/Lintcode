/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/segment-tree-modify
@Language: C++
@Datetime: 16-09-27 07:40
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if(root == NULL || root->start>index || root->end<index) return;
        
        if(root->start == index && root->end == index)
        {
            root->max = value;
            return;
        }
        
        modify(root->left,index, value);
        modify(root->right,index, value);
        
        //Update;
        int left_max = root->left == NULL ? INT_MIN : root->left->max;
        int right_max = root->right == NULL ? INT_MIN : root->right->max;
        root->max = max(left_max,right_max);
        return;
    }
    
};