/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/segment-tree-build
@Language: C++
@Datetime: 16-09-27 07:17
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if(start>end) return NULL;
        SegmentTreeNode * root = new SegmentTreeNode(start,end);
        if(start == end) return root;
        int mid = (start+end)/2;
        root->left = build(start,mid);
        root->right = build(mid+1,end);
        return root;
    }
};