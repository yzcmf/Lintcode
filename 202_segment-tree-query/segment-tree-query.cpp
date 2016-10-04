/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/segment-tree-query
@Language: C++
@Datetime: 16-09-30 00:13
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
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if(root->end<start || root->start>end || root == NULL) return INT_MIN;
        if(root->end<=end && root->start>=start) return root->max;

        int left_max = query(root->left,start,end);
        int right_max = query(root->right,start,end);
    
        return max(left_max,right_max);
    }
};