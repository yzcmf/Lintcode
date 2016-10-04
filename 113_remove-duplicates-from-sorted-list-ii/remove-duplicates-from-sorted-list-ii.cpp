/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-list-ii
@Language: C++
@Datetime: 16-09-26 04:58
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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL ) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        
        while(p->next && p->next->next)
        {
            if(p->next->val == p->next->next->val)
            {
              int val = p->next->val;    
              while(p->next && p->next->val == val)
              {
               ListNode* t = p->next;
               p->next = p->next->next;
               t->next = NULL;
               delete t;
              }
            }
            else
            {
            p = p->next;
            }
        }
        return dummy->next;
    }
};