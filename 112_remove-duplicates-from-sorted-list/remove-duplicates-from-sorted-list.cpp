/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-list
@Language: C++
@Datetime: 16-09-15 22:55
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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode * p = head;
        
        while(p && p->next)
        {
            if(p->val == p->next->val)
            {
             ListNode * t = p->next;
             p->next= t->next;
             t->next= NULL;
             delete t;
            }
            else
            {
            p = p->next;
            }
        }
        
        return head;
    }
};