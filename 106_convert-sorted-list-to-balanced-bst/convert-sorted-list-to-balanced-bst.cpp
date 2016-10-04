/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/convert-sorted-list-to-balanced-bst
@Language: C++
@Datetime: 16-09-20 22:20
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode * sortedListToBST(ListNode *head) {
        // write your code here
       int len = 0;
       ListNode* cur = head;
       while(cur)
       {
           len++;
           cur = cur->next;
       }
       TreeNode * root = sortedListToBST(head,0,len-1);
       return root;
    }
    
     TreeNode * sortedListToBST(ListNode *&head,int start,int end)
    {
        if(start>end) return NULL;
        int mid = (start+end)/2;
        TreeNode * leftChild = sortedListToBST(head,start,mid-1);
        TreeNode * root = new TreeNode(head->val);
        head = head->next;
        TreeNode * rightChild = sortedListToBST(head,mid+1,end);
        root->left = leftChild;
        root->right = rightChild;
        return root;
    }
};


