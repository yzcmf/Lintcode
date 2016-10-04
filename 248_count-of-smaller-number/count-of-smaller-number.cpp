/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/count-of-smaller-number
@Language: C++
@Datetime: 16-09-19 04:00
*/

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        vector<int> res;
        
        //Sort array before building segment tree.
        sort(A.begin(),A.end());
        
        //Build segment tree.
        SegmentTreeNode *root = build(A,0,A.size()-1);
        
        //Do each query
        for(const auto& q: queries)
        {
         res.push_back(query(root,0,A.size()-1,A,q));
        }
        
        return res;
    }
    
    //Build segment tree.
    SegmentTreeNode *build(vector<int> &A,int start,int end)
    {
        if(start>end) return NULL;
        SegmentTreeNode * root = new SegmentTreeNode(start,end,0);
        if(start == end)
        {
            root->count =1;
            return root;
        }
        
        root->left  = build(A,start,(start+end)/2);
        root->right = build(A,(start+end)/2+1,end);
        
        int left_count = root->left != NULL ? root->left->count : 0;
        int right_count = root->right != NULL ? root->right->count : 0;
    
        root->count = left_count + right_count;
        return root;
    }
    
    int query(SegmentTreeNode*root,int start,int end,vector<int>&A,int q)
    {
        if(root == NULL || root->start>end || root->end<start)
        return 0;
        
        if(q<=A[root->start]) return 0;
        
        if(q>A[root->end]) return root->count;
        
        int left  = query(root->left,start,end,A,q);
        int right = query(root->right,start,end,A,q);
        
        //Find count int the children.
        return left+right;
    }
};