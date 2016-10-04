/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/segment-tree-build-ii
@Language: C++
@Datetime: 16-09-27 07:25
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
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        return buildHelper(A,0,A.size()-1);
    }
    
    SegmentTreeNode * buildHelper(vector<int>& A,int start,int end )
    {
        if(start>end) return NULL;
        SegmentTreeNode * root = new SegmentTreeNode(start,end,INT_MAX);
        if(start == end)
        {
            root->max = A[start];
            return root;
        }
        int mid = (start + end) /2;
        root->left = buildHelper(A,start,mid);
        root->right = buildHelper(A,mid+1,end);
        
        int left_max = root->left == NULL ? 0 : root->left->max;
        int right_max = root->right == NULL ? 0 : root->right->max;
        
        root->max = max(left_max,right_max);
        return root;
    }
    
    
};