/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/partition-list
@Language: C++
@Datetime: 16-09-15 05:15
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
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        //write your code here
        
        if(head==NULL) return NULL;
        
        //We need four marks and learn how to make them together;
        
        ListNode * p=head;
        ListNode *leftdummy= new ListNode(0);
        ListNode *left= leftdummy;
        ListNode *rightdummy= new ListNode(0);
        ListNode *right= rightdummy;

        
        while(p)
        {
            if(p->val<x)
            {
              left->next = p;
              left=left->next;
            }else
            {
              right->next = p;
              right =right->next;
            }
          p=p->next;
        }
        
        right->next=NULL;
        left->next=rightdummy->next;
        
        return leftdummy->next;
    }
};


