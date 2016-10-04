/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/add-two-numbers
@Language: C++
@Datetime: 16-09-13 06:55
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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode * dummy  = new ListNode(0),*p=dummy;
        int carry = 0;
        
        while(l1 || l2 || carry)
        {
         if(l1)
         {
          carry += l1->val; 
          l1 = l1->next;
         }
         
         if(l2)
         {
          carry += l2->val; 
          l2 = l2->next;
         } 
         
          p->next = new ListNode(carry%10);
          carry /= 10;
          p = p->next;
        }
        
        return dummy->next;
    }
};