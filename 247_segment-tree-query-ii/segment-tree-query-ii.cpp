/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/segment-tree-query-ii
@Language: C++
@Datetime: 16-09-30 00:37
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
// query(1, 2) means: [1,2];
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if(root == NULL || start>root->end || end<root->start) return 0;
        if (start <= root->start && root->end <= end ) 
        return root->count;   

        int left = query(root->left,start,end);
        int right = query(root->right,start,end);
        
        //root->count = left + right; // This could be wrong, we are not modifing the tree;
        return left + right;
    }
};