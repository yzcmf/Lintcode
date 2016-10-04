/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/rotate-list
@Language: C++
@Datetime: 16-09-27 06:43
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if(head == NULL) return head;
        int len = 0;
        ListNode * p = head;
        while(p)
        {
            len++;
            p = p->next;
        }
        
        k %= len;
        if(k == 0) return head;
        p =head;
        int l = len - k;
        
        while(l-1>0)
        {
            p = p->next;
            l--;
        }
        
        ListNode * newHead = p->next;
        p->next = NULL;
        
        p = newHead;
        while(p->next) 
        {
         p = p->next;
        }
        
        p->next = head;
        
        return newHead;
    }
};