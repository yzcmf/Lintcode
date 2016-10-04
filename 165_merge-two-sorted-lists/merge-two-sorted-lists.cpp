/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-lists
@Language: C++
@Datetime: 16-09-15 03:19
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode * p = new ListNode(0), *newHead;
        newHead = p;
        
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
            p->next = new ListNode(l1->val);
            p = p->next;
            l1 = l1->next;
            }
            else
            {
             p->next = new ListNode(l2->val);
             p = p->next;
             l2 = l2->next;
            }
        }
        
        p->next = (l1) ? l1 : l2 ; 
        
        ListNode * head = newHead->next;
        delete newHead,p;
        
        return head;
        
    }
};