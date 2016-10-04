/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/reverse-linked-list-ii
@Language: C++
@Datetime: 16-09-30 05:51
*/

/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if(head == NULL || m>n) return NULL;
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * node = dummy;
        
        for(int i=1;i<m;i++)
        {
            if(node->next == NULL) return NULL;
            node = node->next;
        }
        
        ListNode * Pre_mnode = node;
        ListNode * mnode = node->next;
        ListNode * nnode = mnode;
        ListNode * Post_nnode = nnode->next;
        
        for(int i=m;i<n;i++)
        {
            if(Post_nnode == NULL) return NULL;
          
            ListNode * t = Post_nnode->next;
            Post_nnode->next = nnode;
            nnode = Post_nnode;
            Post_nnode = t;
        }
        
        Pre_mnode->next = nnode;
        mnode->next = Post_nnode;
        
        return dummy->next;
    }
};
