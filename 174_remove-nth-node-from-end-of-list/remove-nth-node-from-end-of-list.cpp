/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/remove-nth-node-from-end-of-list
@Language: C++
@Datetime: 16-09-15 23:17
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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode * p = head;
        int len = 0;
        
        while(p)
        {
            len++;
            p = p->next;
        }
        
        if(n == len) 
        {
            head = head->next;
            return head;
        }

        
        p = head;
        
        // p->next will point to the delete node;
        while(n<len-1)
        {
            n++;
            p = p->next;
        }
        
        ListNode * t = p->next;
        p->next = t->next;
        t ->next = NULL;
        delete t;
        
        return head;
    }
};


