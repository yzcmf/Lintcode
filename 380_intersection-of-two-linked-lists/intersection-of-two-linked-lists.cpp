/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/intersection-of-two-linked-lists
@Language: C++
@Datetime: 16-09-22 23:26
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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        int l1 = 0;
        int l2 = 0;
        ListNode * a = headA;
        ListNode * b = headB;
        
        while(a)
        {
            a = a->next;
            l1++;
        }
        
        while(b)
        {
            b = b->next;
            l2++;
        }
        
        a = headA;
        b = headB;
        
        while(l1 && l2)
        {
            while(l1>l2)
            {
                a = a->next;
                l1--;
            }
            
            while(l2>l1)
            {
                b = b->next;
                l2--;
            }
            
            if( l1 == l2)
            {
                if(a == b) return a;
                else
                {
                    l1--;
                    l2--;
                    a = a->next;
                    b = b->next;
                }
            }
        }
        
        return NULL;
    }
};